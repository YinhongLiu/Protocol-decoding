#include <stdio.h>
#include "Ecg.h"
#include "EcgType.h"

void main()
{
	u8 data[] = {0x01,0x97,0x80,0x80,0x80,0x80,0x9C};
	u8 i,len,pid;

	len	= sizeof(data);
	for(i=0;i<len;i++)
	{
		pid = UnpackEcgData(data[i]);
		switch(pid)
		{
		case PACK_ID_01:
			printf("Ecg1=%d\n",GetEcgData(ECG_DATA_ECG1));
			printf("Ecg2=%d\n",GetEcgData(ECG_DATA_ECG2));
			printf("Ecg3=%d\n",GetEcgData(ECG_DATA_ECG3));
			break;
		}
	}
}