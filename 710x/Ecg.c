#include "Ecg.h"
#include "710x.h"
#include "EcgType.h"

typedef enum
{
	POS_CNT_ECG1 = 1,
	POS_CNT_ECG2 = 1,
	POS_CNT_ECG3 = 1,
	POS_CNT_BEAT = 1,
	POS_CNT_PACE = 1,
	POS_CNT_CH1 = 1,
	POS_CNT_CH2 = 1,
	POS_CNT_CH3 = 1,
	POS_CNT_RESP = 1,
};


typedef enum
{
	PACK_LEN_01 = 7,
};

typedef enum
{
	PACK_VAR_01 = 9,
};

static i32 sEcgData[ECG_DATA_MAX] = {0};
static u8 sPackBuf[_710X_PACK_LEN] = {0};

static const _710xPos sPosEcg1[POS_CNT_ECG1] = {{0,	8,	2,	0}};
static const _710xPos sPosEcg2[POS_CNT_ECG2] = {{0,	8,	3,	0}};
static const _710xPos sPosEcg3[POS_CNT_ECG3] = {{0,	8,	4,	0}};
static const _710xPos sPosBeat[POS_CNT_BEAT] = {{0,	1,	5,	0}};
static const _710xPos sPosPace[POS_CNT_PACE] = {{0,	1,	5,	1}};
static const _710xPos sPosCh1[POS_CNT_CH1] = {{0,	1,	5,	2}};
static const _710xPos sPosCh2[POS_CNT_CH2] = {{0,	1,	5,	3}};
static const _710xPos sPosCh3[POS_CNT_CH3] = {{0,	1,	5,	4}};
static const _710xPos sPosResp[POS_CNT_RESP] = {{0,	8,	6,	0}};

static const _710xVar sVarEcg1 = {POS_CNT_ECG1,	sPosEcg1};
static const _710xVar sVarEcg2 = {POS_CNT_ECG2,	sPosEcg2};
static const _710xVar sVarEcg3 = {POS_CNT_ECG3,	sPosEcg3};
static const _710xVar sVarBeat = {POS_CNT_BEAT,	sPosBeat};
static const _710xVar sVarPace = {POS_CNT_PACE,	sPosPace};
static const _710xVar sVarCh1 = {POS_CNT_CH1,	sPosCh1};
static const _710xVar sVarCh2 = {POS_CNT_CH2,	sPosCh2};
static const _710xVar sVarCh3 = {POS_CNT_CH3,	sPosCh3};
static const _710xVar sVarResp = {POS_CNT_RESP,	sPosResp};
static const _710xVar* sVarPack01[PACK_VAR_01] = {&sVarEcg1,	&sVarEcg2,	&sVarEcg3,	&sVarBeat,	&sVarPace,	&sVarCh1,	&sVarCh2,	&sVarCh3,	&sVarResp};

static const _710xPack sPack01 = {PACK_ID_01,	PACK_LEN_01,	PACK_VAR_01,	sEcgData+ECG_DATA_ECG1,	sVarPack01};
static const _710xPack* sEcgPack[ECG_PACK_MAX] = {&sPack01};
static _710xUnpack sEcgUnpack = {sPackBuf,	0,	0};
static _710xPro sEcgPro = {ECG_PACK_MAX,	sEcgData,	ECG_DATA_MAX,	sEcgPack,	&sEcgUnpack};


u8 UnpackEcgData(u8 d)
{
	return Unpack710xData(&sEcgPro,d);
}

i32 GetEcgData(u8 type)
{
	return Get710xData(&sEcgPro,type);
}