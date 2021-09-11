#include "getUserName.hpp"

std::string getUserName()
{
	const int INFO_BUFFER_SIZE = 32767;
	TCHAR  infoBuff[INFO_BUFFER_SIZE];
	DWORD  bufCharCount = INFO_BUFFER_SIZE;
	if (!GetUserName(infoBuff, &bufCharCount))
	{
		return "error!";
	}
	else
	{
		std::wstring wideString(&infoBuff[0]);
		std::string nString(wideString.begin(), wideString.end());
		return nString;
	}
}