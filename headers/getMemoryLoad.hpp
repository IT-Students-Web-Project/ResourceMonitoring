#pragma once
#include <Windows.h>

#ifndef getMemoryLoad_hpp
#define getMemoryLoad_hpp

DWORDLONG getTotalVirtualMemory();
DWORDLONG getTotalPhysicalMemory();
DWORDLONG getVirtualMemoryLoad();
DWORDLONG getPhysicalMemoryLoad();

#endif