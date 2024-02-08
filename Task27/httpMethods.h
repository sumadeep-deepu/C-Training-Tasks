#ifndef HTTP_METHODS
#define HTTP_METHODS
#include<iostream>

#include<string>

class httpMethods{
	public:
		static std::string httpGet(const std::string& url);
		static std::string httpPost(const std::string& url,const std::string& data);
};

#endif

