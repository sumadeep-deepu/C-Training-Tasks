#include <iostream>
#include <winsock2.h>
using namespace std;
int main()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cerr << "failed to initialize winsock" << endl;
		return 1;
	}
	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET)
	{
		cerr << "failed to create socket" << endl;
		WSACleanup();
		return 1;
	}
	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddress.sin_port = htons(12345);

	if (connect(clientSocket, (sockaddr *)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
	{
		cerr << "failed to connect to the server" << endl;
		WSACleanup();
		closesocket(clientSocket);
		return 1;
	}

	char buffer[1024];
	string messege;
	do
	{
		cout << "enter a messege or (type 'exit' to quit)" << endl;
		getline(cin, messege);

		send(clientSocket, messege.c_str(), messege.length(), 0);
		if (messege == "exit")
		{
			break;
		}

		int bytes = recv(clientSocket, buffer, sizeof(buffer), 0);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			cout << buffer << endl;
		}
	} while (true);

	WSACleanup();
	closesocket(clientSocket);
	return 0;
}
