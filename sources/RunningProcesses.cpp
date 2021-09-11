#include "RunningProcesses.h"

RunningProcesses::RunningProcesses() { findRunningProcesses(); }

RunningProcesses::~RunningProcesses() {
	for (int i = 0; i < runinigProcessesNumber; i++)
	{
		runningProcessesArray[i] = nullptr;
		delete[] runningProcessesArray[i];
	}
	delete[] runningProcessesArray;
}

int RunningProcesses::getRuninigProcessesNumber() { return runinigProcessesNumber; }

std::string** RunningProcesses::getRunningProcessesArray() { return runningProcessesArray; }

void RunningProcesses::findRunningProcesses()
{
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		runinigProcessesNumber = 0;
		return;
	}

	cProcesses = cbNeeded / sizeof(DWORD);
	runinigProcessesNumber = cProcesses;
	runningProcessesArray = new std::string * [runinigProcessesNumber];
	for (int i = 0; i < cProcesses; i++)
	{
		runningProcessesArray[i] = new std::string[2];
		std::ostringstream stream;
		stream << aProcesses[i];
		runningProcessesArray[i][0] = stream.str();
		if (aProcesses[i] != 0)
		{
			runningProcessesArray[i][1] = findProcessName(aProcesses[i]);
		}
		else
		{
			runningProcessesArray[i][1] = "system";
		}
	}
}

std::string RunningProcesses::findProcessName(DWORD processID)
{
	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION | PROCESS_VM_READ, FALSE, processID);
	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;
		if (EnumProcessModulesEx(hProcess, &hMod, sizeof(hMod), &cbNeeded, LIST_MODULES_ALL))
		{
			GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
		}
	}
	CloseHandle(hProcess);
	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;
	std::string returnString = converter.to_bytes((std::wstring)szProcessName);
	return returnString;
}
