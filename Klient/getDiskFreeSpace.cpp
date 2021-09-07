#include "getDiskFreeSpace.hpp"

int getDiskFreeSpacePercentage()
{
	DWORD lpSectorsPerCluster,
		lpBytesPerSector,
		lpNumberOfFreeClusters,
		lpTotalNumberOfClusters;

	if (GetDiskFreeSpace(NULL,
		&lpSectorsPerCluster,
		&lpBytesPerSector,
		&lpNumberOfFreeClusters,
		&lpTotalNumberOfClusters))
	{
		return int(double(lpNumberOfFreeClusters) / double(lpTotalNumberOfClusters) * 100.0);
	}
	else
	{
		return 0;
	}
}