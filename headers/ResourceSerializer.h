#pragma once
#include <map>
#include "nlohmann/json.hpp"
#include "getCpuLoad.hpp"
#include "getMemoryLoad.hpp"
#include "getDiskFreeSpace.hpp"
#include "getHostName.hpp"
#include "getUserName.hpp"
#include "RunningProcesses.h"
using json = nlohmann::json;

class ResourceSerializer {
private:
	json resources;
	void updateResources();
public:
	ResourceSerializer();
	json getResourcesJson();
};