#include "resources.h"

void Resources::updateLists()
{
    cpuLoadList.push_front(cpuLoad);
        cpuLoadList.pop_back();
    diskFreeSpacePercentageList.push_front(diskFreeSpacePercentage);
        diskFreeSpacePercentageList.pop_back();
    memoryLoadList.push_front(memoryLoad);
        memoryLoadList.pop_back();
}

Resources::Resources()
{
    for (int i =0; i < 30; i++){
        cpuLoadList.push_front(0.0f);
        diskFreeSpacePercentageList.push_front(0.0f);
        memoryLoadList.push_front(0.0f);
    }
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
