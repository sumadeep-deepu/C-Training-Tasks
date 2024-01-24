#include <iostream>
#include <winsock2.h>
using namespace std;
int main()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cerr << "failed to initilaize the winwsock" << endl;
		return 1;
	}

	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == INVALID_SOCKET)
	{
		cerr << "failed to create socket" << endl;
		WSACleanup();
		return 1;
	}

	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port = htons(12112);

	if (bind(serverSocket, (sockaddr *)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
	{
		cerr << "binding of the socket failed" << endl;
		closesocket(serverSocket);
		WSACleanup();
		return 1;
	}
	if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		cerr << "Listening to the server failed " << endl;
		closesocket(serverSocket);
		WSACleanup();
		return 1;
	}
	cout << "server listening to the port on 121121" << endl;

	SOCKET clientSocket;
	sockaddr_in clientAddress;
	int clientAddressSize=sizeof(clientAddress);
	clientSocket=accept(serverSocket,(sockaddr*)&clientAddress,&clientAddressSize);

	if (clientSocket == INVALID_SOCKET)
	{
		cerr << "accept failed!!!" << endl;
		closesocket(serverSocket);
		WSACleanup();
		return 1;
	}

	char buffer[1024] = {0};
	recv(clientSocket, buffer, sizeof(buffer), 0);
	cout << "recived from client : " << buffer << endl;

	const char *response = "Hello this is from server";
	send(clientSocket, response, strlen(response), 0);

	closesocket(clientSocket);
	closesocket(serverSocket);
	WSACleanup();

	return 0;
}
