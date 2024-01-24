#include <iostream>
#include <winsock2.h>
#include <thread>
#include <vector>
using namespace std;
#pragma comment(lib, "ws2_32.lib");
int count = 0;

void responseToClient(SOCKET clientSocket)
{
	char buffer[1024];
	int bytes;
	do
	{
		bytes = recv(clientSocket, buffer, sizeof(buffer), 0);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			cout << "recived from client" << count + 1 << " :  " << buffer << endl;
			char *response = "hi from server";
			send(clientSocket, response, strlen(response), 0);
		}
	} while (bytes > 0);
	count++;
	closesocket(clientSocket);
}
int main()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cerr << "initialzation of winsock failed";
		return 1;
	}

	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == INVALID_SOCKET)
	{
		cerr << "failed to create a socket" << endl;
		WSACleanup();
		return 1;
	}

	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port = htons(12312);

	if (bind(serverSocket, (sockaddr *)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
	{
		cerr << "binding failed" << endl;
		WSACleanup();
		closesocket(serverSocket);
		return 1;
	}

	if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		cerr << "listening failed!!" << endl;
		closesocket(serverSocket);
		WSACleanup();
		return 1;
	}

	cout << "server listening on port 12312" << endl;

	vector<thread> clients;
	while (true)
	{
		SOCKET clientSocket;
		sockaddr_in clientAddress;
		int clientAddressSize=sizeof(clientAddress);
		clientSocket = accept(serverSocket, (sockaddr *)&clientAddress,&clientAddressSize );
		if (clientSocket == INVALID_SOCKET)
		{
			cerr << "accept failed" << endl;
			closesocket(serverSocket);
			WSACleanup();
			return 1;
		}
		clients.emplace_back(responseToClient, clientSocket);
	}
	for (auto &it : clients)
	{
		it.join();
	}
	closesocket(serverSocket);
	WSACleanup();
	return 0;
}
