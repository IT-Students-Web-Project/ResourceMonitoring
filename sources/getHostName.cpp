#include "getHostName.hpp"

std::string getHostName()
{
	TCHAR  infoBuff[INFO_BUFFER_SIZE];
	DWORD  bufCharCount = INFO_BUFFER_SIZE;
	if (!GetComputerName(infoBuff, &bufCharCount))
	{
		return "error!";
	}
	else
	{
		return infoBuff;
	}
}