#ifndef RESOURCES_H
#define RESOURCES_H
#include <string>
#include <map>
#include <list>
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
    std::list<unsigned long long> memoryLoadList;
    std::list<float> diskFreeSpacePercentageList;
    std::list<float> cpuLoadList;
    void updateLists();

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
    std::list<unsigned long long> getMemoryLoadListReference() {return memoryLoadList;}
    std::list<float> getDiskFreeSpacePercentageList() {return diskFreeSpacePercentageList;}
    std::list<float> getCpuLoadList() {return cpuLoadList;}
};

#endif // RESOURCES_H
