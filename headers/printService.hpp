#pragma once

#ifndef printService_hpp
#define printService_hpp

#include <iostream>
#include "resourceSerializer.hpp"
#include "runningProcesses.hpp"
#include "resourceSerializer.hpp"
#include "getCpuLoad.hpp"
#include "getDiskFreeSpace.hpp"
#include "getMemoryLoad.hpp"
#include "getUserName.hpp"
#include "getHostName.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>

void printCpuLoad();

void printMemoryLoad();

void printDiskFreeSpace();

void printUserName();

void printHostName();

void printRunningProcesses();

void printJsonToFile();

#endif