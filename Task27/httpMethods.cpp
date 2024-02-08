#include "httpMethods.h"
#include <curl/curl.h>

unsigned int writeback(void *contents, unsigned int size, unsigned int noOfMem, std::string *output)
{
	unsigned int totalSize = size * noOfMem;
	output->append(static_cast<char *>(contents), totalSize);
	return totalSize;
}
std::string httpMethods::httpGet(const std::string &url)
{
	CURL *curl;
	CURLcode result;
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	std::string response;

	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

		result = curl_easy_perform(curl);

		if (result != CURLE_OK)
		{
			std::cerr << "curl_easy_perform() function failed" << std::endl;
			std::cerr << "ERROR in getting http GET request" << std::endl;
		}
	}
	curl_global_cleanup();
	return response;
}
std::string httpMethods::httpPost(const std::string &url, const std::string &data)
{
	CURL *curl;
	CURLcode result;
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	std::string response;

	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

		result = curl_easy_perform(curl);
		if (result != CURLE_OK)
		{
			std::cerr << "Curl_easy_perfrom() function failed" << std::endl;
			std::cerr << "ERROR in getting http POST response" << std::endl;
			return "error";
		}
	}
	curl_global_cleanup();
	return response;
}
