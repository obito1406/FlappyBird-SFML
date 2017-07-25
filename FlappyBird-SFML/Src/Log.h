#pragma once
#include <string>
#include <iostream>
 
namespace FlappyBird
{
class Log 
{
public: 
	static Log* Get();
	~Log();		
	void WriteLog(std::string comment, const char* filename, const char* function, int line);

	//__PRETTY_FUNCTION__ and __FUNCTION__ could be used too
	#define WRITELOG(comment) Log::Get()->WriteLog(comment, __FILE__, __func__,  __LINE__); 

private:
	static Log* mInstance;	//Why static? is it needed?
	Log() {};
	Log(Log const&) {}; //This way it cannot used the copy construct
	Log& operator=(Log const&) {}; //this way it cannot be copied using = operator


};
}