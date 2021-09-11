#include "ResourceSerializer.h"

void ResourceSerializer::updateResources()
{
	resources["hostName"] = getHostName();
	resources["userName"] = getHostName();
	resources["cpuLoad"] = GetCPULoad();
	resources["totalMemory"] = getTotalPhysicalMemory();
	resources["memoryLoad"] = getPhysicalMemoryLoad();
	resources["diskFreeSpacePercentage"] = getDiskFreeSpacePercentage();
	RunningProcesses processes;
	std::string** processesArr = processes.getRunningProcessesArray();
	std::map<int, std::string> processesMap;
	int n = processes.getRuninigProcessesNumber();
	for (int i = 0; i < n; i++)
	{
		processesMap.insert({ atoi(processesArr[i][0].c_str()), processesArr[i][1] });
	}
	for (int i = 0; i < n; i++)
	{
		processesArr[i] = nullptr;
		delete[] processesArr[i];
	}
	resources["processesMap"] = processesMap;
}

ResourceSerializer::ResourceSerializer()
{
	updateResources();
}

json ResourceSerializer::getResourcesJson()
{
	updateResources();
	return resources;
}
