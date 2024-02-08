#include "httpMethods.h"
#include <iostream>
int main()
{
	std::string getUrl = "https://dummy.restapiexample.com/api/v1/employee/1";
	std::string postUrl = "https://dummy.restapiexample.com/api/v1/create";
	std::string data = R"({"title":"fine","body":"bar","id":1})";

	std::cout << "HTTP GET RESPONSE IS :" << httpMethods::httpGet(getUrl) << std::endl;
	std::cout << "HTTP POST RESPONSE IS :" << httpMethods::httpPost(postUrl, data) << std::endl;

	return 0;
}
