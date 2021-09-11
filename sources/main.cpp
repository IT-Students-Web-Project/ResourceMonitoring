// Klient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iomanip>
#include <iostream>
#include <fstream>
#include "ResourceSerializer.h"

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

void printJosnToFile() {
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

int main(){
    printJosnToFile();
    printUserName();
    printHostName();
    printRunningProcesses();

    while (true) {
        printCpuLoad();
        printMemoryLoad();
        printDiskFreeSpace();
        std::cout << std::endl << std::endl << std::endl;
        Sleep(1000);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
