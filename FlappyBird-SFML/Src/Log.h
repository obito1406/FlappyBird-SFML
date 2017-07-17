#pragma once
#include <string>
#include <iostream>
 
namespace FlappyBird
{
class Log 
{
public: 
	//__PRETTY_FUNCTION__ and __FUNCTION__ could be used too
	#define WRITELOG(comment) Log::WriteLog(comment, __FILE__, __func__,  __LINE__);

	void static WriteLog(std::string comment, const char* filename, const char* function, int line)  
	{
		std::cout << filename << "::" << function << "::Line(" << line << ") " << comment << std::endl;
	}
};
}