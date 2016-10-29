#include "Bcg.h"
#include "Instance.h"
#include "InstanceType.h"

typedef enum
{
	//MOD19_PACK01
	SEGNUM_SIGNAL_WAVE = 2,
	SEGNUM_DYNAMIC_WAVE = 2
};
typedef enum
{
	//MOD19
	M19_P01_VAR_NUM = 2,
	M19_P02_VAR_NUM = 2
};
typedef enum
{
	M19_PACK_NUM = 11
};
#define  MOD_NUM  2


static unsigned char sBufferPack[BCG_PACK_LEN] = {0};
static BcgUnpackTool sUnpackTool = {0, 0, sBufferPack};
//-----------------------------------------------MOD_19-----------------------------------------------------------------------------------------------------------------------

static int sMod19VarVal[MOD_19_VAR_TOTAL_NUM] = {0};

//MOD_19 PACK_01 BLOCK
static BcgPosSeg sPosSignalWave[SEGNUM_SIGNAL_WAVE] = {
	{3, 0, 8, 8},
	{4, 0, 8, 0}
};
static BcgPosSeg sPosDynamicWave[SEGNUM_DYNAMIC_WAVE] = {
	{5, 0, 8, 8},
	{6, 0, 8, 0}
};
static BcgVar sVarSignalWave = {sPosSignalWave, SEGNUM_SIGNAL_WAVE};
static BcgVar sVarDynamicWave = {sPosDynamicWave, SEGNUM_DYNAMIC_WAVE};

static BcgVar* sPack01Var[] = {&sVarSignalWave, &sVarDynamicWave};
static BcgPack sPack01 = {sPack01Var, sMod19VarVal+VAR_01_SIGNAL_WAVE, M19_P01_VAR_NUM, PACK_01_ID};



static BcgPack* sMod19PackList[] = {&sPack01};

static BcgMod sMod19 = {sMod19PackList, M19_PACK_NUM, MOD_19_ID, sMod19VarVal, MOD_19_VAR_TOTAL_NUM};
static BcgPro sBcgProM19 = {&sMod19, &sUnpackTool};
//===============================================END=================================================================================================================================





void UnpackM19Data(unsigned char d)
{
	 UnpackBcgData(&sBcgProM19,d);
}
int GetData(unsigned char modType, unsigned char varType)
{
	BcgMod* pMod;
	switch (modType)
	{
	case MOD_19_ID:
		pMod = &sMod19;
		break;
	case MOD_30_ID:
		break;
	}
	return GetVarVal(pMod,varType);
}
void SetData(unsigned char modType, unsigned char varType, int data)
{
	BcgMod* pMod;
	switch (modType)
	{
	case MOD_19_ID:
		pMod = &sMod19;
		break;
	case MOD_30_ID:
		break;
	}
	SetVarVal(pMod,varType,data);
}