#include "resources.h"

void Resources::updateLists()
{
    cpuLoadList.push_front(cpuLoad);
    if(cpuLoadList.size() > 30)
        cpuLoadList.pop_back();
    diskFreeSpacePercentageList.push_front(diskFreeSpacePercentage);
    if(diskFreeSpacePercentageList.size() > 30)
        diskFreeSpacePercentageList.pop_back();
    memoryLoadList.push_front(memoryLoad);
    if(memoryLoadList.size() > 30)
        memoryLoadList.pop_back();
}

Resources::Resources()
{

}

void Resources::DeserializeJson(json resourcesJson)
{
    hostName = resourcesJson["hostName"];
    userName = resourcesJson["userName"];
    totalMemory = resourcesJson["totalMemory"];
    memoryLoad = resourcesJson["memoryLoad"];
    diskFreeSpacePercentage = resourcesJson["diskFreeSpacePercentage"];
    cpuLoad = resourcesJson["cpuLoad"];
    processesMap= resourcesJson["processesMap"].get<std::map<int, std::string>>();
    updateLists();
}
