#include <stdio.h>
#include "Instance.h"
#include "InstanceType.h"

void main()
{
	unsigned char packData[] = {0x19, 0x90, 0x81, 0x88, 0x88, 0x87, 0xf5, 0x80, 0x80, 0xb6};
	unsigned char len,i,s;
//	ModAndPackType Type;
	len = sizeof(packData)/sizeof(unsigned char);

	for (i=0;i<len;i++)
	{
		UnpackM19Data(packData[i]);
	}
	printf("%d    %d",GetData(MOD_19_ID, VAR_01_SIGNAL_WAVE),GetData(MOD_19_ID,VAR_01_DYNAMIC_WAVE));
	scanf("%d",&s);
}