#include<iostream>
#include<winsock2.h>
using namespace std;
int main(){
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0){
		cerr<<"failed to initialize the winsock!!"<<endl;
		WSACleanup();
		return 1;
	}

	SOCKET clientSocket=socket(AF_INET,SOCK_STREAM,0);
	if(clientSocket==INVALID_SOCKET){
		cerr<<"failed to create the socket"<<endl;
		WSACleanup();
		return 1;
	}

	sockaddr_in serverAddress;
	serverAddress.sin_family=AF_INET;
	serverAddress.sin_addr.s_addr=inet_addr("127.0.0.1");
	serverAddress.sin_port=htons(12312);

	if(connect(clientSocket,(sockaddr*)&serverAddress,sizeof(serverAddress))==SOCKET_ERROR){
		cerr<<"connecting to the server failed";
		closesocket(clientSocket);
		WSACleanup();
		return 1;
	}
	const char* messege="hello this is from client1";
	send(clientSocket,messege,strlen(messege),0);


	char buffer[1024]={0};
	recv(clientSocket,buffer,sizeof(buffer),0);
	cout<<"recieved from server : "<<buffer<<endl;
	closesocket(clientSocket);
	WSACleanup();

	return 0;
}


