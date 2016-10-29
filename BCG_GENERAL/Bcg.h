#ifndef _BCG_H_
#define _BCG_H_

#define BCG_PACK_LEN 10
typedef struct  
{
	unsigned char bytePos;
	unsigned char bitPosInByte;
	unsigned char bitLen;
	unsigned char bitPosInVar;
}BcgPosSeg;

typedef struct  
{
	BcgPosSeg* pVarPosSeg;
	unsigned char varPosSegNum;
}BcgVar;

typedef struct  
{
	BcgVar** pVarList;
	int* pVarValListInPack;
	unsigned char varNumInPack;
	unsigned char packId;
}BcgPack;

typedef struct
{
	BcgPack** pPackList;
	unsigned char packNum;
	unsigned char modID;
	int* pVarValListInMod;
	unsigned char varNumInMod;
}BcgMod;

typedef struct  
{
	unsigned char currentLen;
	BcgPack* pCurrentPack;
	unsigned char* pBufferPack;
}BcgUnpackTool;

typedef struct
{
	BcgMod* pMod;
	BcgUnpackTool* pUnpackTool;

}BcgPro;

int GetVarVal(BcgMod* pBcgMod, unsigned char varType);
void SetVarVal(BcgMod* pBcgMod, unsigned char varType, int data);
void UnpackBcgData(BcgPro* pBcgPro, unsigned char d);
#endif