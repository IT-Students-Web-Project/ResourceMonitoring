#include "getMemoryLoad.hpp"

enum class memoryType {
	totalVirtualMem, 
	totalPhysMem,
	virtualMemUsed,
	physMemUsed
};

DWORDLONG getMemoryLoad(memoryType type) {
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);

	//  Virtual memory
	DWORDLONG totalVirtualMem = memInfo.ullTotalPageFile;
	//  Physical memory
	DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
	//  Virtual memory used
	DWORDLONG virtualMemUsed = memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;
	//  Physical memory used
	DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

	return (type == memoryType::totalVirtualMem) ? totalVirtualMem : (type == memoryType::totalPhysMem) ? totalPhysMem :
		(type == memoryType::virtualMemUsed) ? virtualMemUsed : (type == memoryType::physMemUsed) ? physMemUsed : DWORDLONG("ERROR");
}

DWORDLONG getTotalVirtualMemory() {
	return (getMemoryLoad(memoryType::totalVirtualMem) /1024) /1024;
}
DWORDLONG getTotalPhysicalMemory() {
	return (getMemoryLoad(memoryType::totalPhysMem) /1024) /1024;
}
DWORDLONG getVirtualMemoryLoad() {
	return (getMemoryLoad(memoryType::virtualMemUsed) /1024) /1024;
}
DWORDLONG getPhysicalMemoryLoad() {
	return (getMemoryLoad(memoryType::physMemUsed) /1024) /1024;
}


