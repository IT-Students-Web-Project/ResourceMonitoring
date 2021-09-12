#ifndef RESOURCES_H
#define RESOURCES_H
#include <string>
#include <map>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Resources
{
private:
    std::string hostName;
    std::string userName;
    unsigned long long totalMemory;
    unsigned long long memoryLoad;
    float diskFreeSpacePercentage;
    float cpuLoad;
    std::map<int, std::string> processesMap;

public:
    Resources();
    void DeserializeJson(json resourcesJson);
    std::string getHostName() {return hostName;}
    std::string getUserName() {return userName;}
    unsigned long long getTotalMemory() {return totalMemory;}
    unsigned long long getMemoryLoad() {return memoryLoad;}
    float getDiskFreeSpacePercentage() {return diskFreeSpacePercentage;}
    float getCpuLoad() {return cpuLoad;}
    std::map<int, std::string> getProcessesMap() {return processesMap;}

};

#endif // RESOURCES_H
