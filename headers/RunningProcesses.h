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
	std::string findProcessName(DWORD processID);
public:
	RunningProcesses();
	~RunningProcesses();
	int getRuninigProcessesNumber();
	std::string** getRunningProcessesArray();
	void findRunningProcesses();
};
