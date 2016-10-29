#ifndef _ECG_TYPE_H_
#define _ECG_TYPE_H_
typedef enum
{
	ECG_DATA_ECG1,
		ECG_DATA_ECG2,
		ECG_DATA_ECG3,
		ECG_DATA_BEAT,
		ECG_DATAE_PACE,
		ECG_DATA_CH1,
		ECG_DATA_CH2,
		ECG_DATA_CH3,
		ECG_DATA_RESP,
		ECG_DATA_MAX
}EcgData;

typedef enum
{
	PACK_ID_01 = 0x01,
};


typedef enum
{
	ECG_PACK_01,
		ECG_PACK_MAX
}Ecgpack;
#endif
