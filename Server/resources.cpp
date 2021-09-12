#include "resources.h"

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
}
