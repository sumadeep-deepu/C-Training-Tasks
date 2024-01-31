#include <iostream>
#include <winsock2.h>
using namespace std;
#pragma comment(lib, "ws2_32.lib")
int main()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cerr << "failed to initialize winsock" << endl;
		return 1;
	}

	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == INVALID_SOCKET)
	{
		cerr << "failed to initialize socket" << endl;
		WSACleanup();
		return 1;
	}

	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port = htons(12345);

	if (bind(serverSocket, (sockaddr *)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
	{
		cerr << "failed to bind " << endl;
		WSACleanup();
		closesocket(serverSocket);
		return 1;
	}

	if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		cerr << "failed to listen to the client" << endl;
		WSACleanup();
		closesocket(serverSocket);
		return 1;
	}
	cout << "server listening on port number 12345 " << endl;

	SOCKET clients[FD_SETSIZE];
	fd_set mainset;
	FD_ZERO(&mainset);
	FD_SET(serverSocket, &mainset);
	int maxfd = serverSocket;

	while (true)
	{
		fd_set tempset = mainset;
		int activity = select(0, &tempset, nullptr, nullptr, nullptr);

		if (activity == SOCKET_ERROR)
		{
			cerr << "select failed" << endl;
			break;
		}

		if (FD_ISSET(serverSocket, &tempset))
		{
			SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
			if (clientSocket == INVALID_SOCKET)
			{
				cerr << "accept failed" << endl;
			}
			else
			{
				cout << "new connection establsiehd" << endl;
				FD_SET(clientSocket, &mainset);
				if (clientSocket > maxfd)
				{
					maxfd = clientSocket;
				}
			}
			FD_CLR(serverSocket, &tempset);
		}

		for (int i = 0; i <= maxfd; i++)
		{
			if (FD_ISSET(i, &tempset))
			{
				char buffer[1024];
				int bytes = recv(i, buffer, sizeof(buffer), 0);
				if (bytes <= 0)
				{
					cout << "client disconnected" << endl;
					closesocket(i);
					FD_CLR(i, &mainset);
				}
				else
				{
					buffer[bytes] = '\0';
					cout << "recived messege from client " << i << " : " << buffer << endl;
					for (int j = 0; j <= maxfd; j++)
					{
						if (FD_ISSET(j, &mainset) && j != serverSocket && j != i)
						{
							send(j, buffer, strlen(buffer), 0);
						}
					}
				}
			}
		}
	}
	closesocket(serverSocket);
	WSACleanup();
	return 0;
}
