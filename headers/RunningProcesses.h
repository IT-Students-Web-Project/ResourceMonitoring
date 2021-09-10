#pragma once
#include <string>;
#include <Windows.h>
#include <psapi.h>
#include <iostream>
#include <sstream>
#include <codecvt>

class RunningProcesses
{
private:
	int runinigProcessesNumber = 0;
	std::string** runningProcessesArray;
public:
	RunningProcesses();
	~RunningProcesses();
	int getRuninigProcessesNumber();
	std::string** getRunningProcessesArray();
	void findRunningProcesses();
	std::string findProcessName(DWORD processID);
};
