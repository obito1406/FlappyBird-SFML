#include "Log.h"

namespace FlappyBird
{
	Log* Log::mInstance = nullptr; //Be aware, since static members can be accesed even without a class(thats static there for you) they have to be initialized with a value
								   // This its usually done on the cpp. On the header if include multiple times could be dangerous.
	
	Log* Log::Get()
	{
		if (mInstance == nullptr)
		{
			mInstance = new Log();
		}
		return mInstance;
	}

	void Log::WriteLog(std::string comment, const char* filename, const char* function, int line)
	{
		std::cout << filename << "::" << function << "::Line(" << line << ") " << comment << std::endl;
	}
}
