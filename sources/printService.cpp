#include "printService.hpp"

void printCpuLoad() {
    std::cout << "CPU load: " << GetCPULoad() << std::endl;
}

void printMemoryLoad() {
    std::cout << "Total physical memory: " << getTotalPhysicalMemory() << std::endl << "Physical memory usage: " << getPhysicalMemoryLoad() << std::endl;
}

void printDiskFreeSpace() {
    std::cout << "Disk free space: " << getDiskFreeSpacePercentage() << "%" << std::endl;
}

void printUserName() {
    std::cout << "User Name: " << getUserName() << std::endl;
}

void printHostName() {
    std::cout << "Host Name: " << getHostName() << std::endl;
}

void printRunningProcesses() {
    RunningProcesses processes;
    std::string** arr = processes.getRunningProcessesArray();
    int n = processes.getRuninigProcessesNumber();
    for (int i = 0; i < n; i++)
    {
        std::cout << "id: " << arr[i][0] << " \tname: " << arr[i][1] << "\n";
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = nullptr;
        delete[] arr[i];
    }
    std::cout << std::endl;
}

void printJsonToFile() {
    ResourceSerializer serializer;
    std::ofstream jsonFile("resources.json");
    if (jsonFile.is_open())
    {
        jsonFile << std::setw(4) << serializer.getResourcesJson() << std::endl;
        std::cout << "Succesfully printed to file!" << std::endl;
        jsonFile.close();
    }
    else std::cout << "Unable to open file!" << std::endl;
}