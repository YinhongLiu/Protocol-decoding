#include "Bcg.h"
static BcgPack* ChosePack(BcgMod* pBcgMod, unsigned char* pBufferPack);  //return pack address
static unsigned char CheckByteSum(unsigned char* pBufferPack);
static void	ResetBit7(unsigned char* pBufferPack);
static int UnpackSingleVar(BcgVar* pBcgVar, unsigned char* pBufferPack);


void UnpackBcgData(BcgPro* pBcgPro, unsigned char d)
{
	unsigned char i;
	if (d == pBcgPro->pMod->modID)
	{
		pBcgPro->pUnpackTool->pBufferPack[0] = d;
		pBcgPro->pUnpackTool->currentLen = 1;
	}
	else if (pBcgPro->pUnpackTool->currentLen < BCG_PACK_LEN)
	{
		pBcgPro->pUnpackTool->pBufferPack[pBcgPro->pUnpackTool->currentLen++] = d;
		if (pBcgPro->pUnpackTool->currentLen == BCG_PACK_LEN)
		{
			if (CheckByteSum(pBcgPro->pUnpackTool->pBufferPack))
			{
				ResetBit7(pBcgPro->pUnpackTool->pBufferPack);

				pBcgPro->pUnpackTool->pCurrentPack = ChosePack(pBcgPro->pMod, pBcgPro->pUnpackTool->pBufferPack);				
				for (i=0;i<pBcgPro->pUnpackTool->pCurrentPack->varNumInPack;i++)
				{
					pBcgPro->pUnpackTool->pCurrentPack->pVarValListInPack[i] = UnpackSingleVar(pBcgPro->pUnpackTool->pCurrentPack->pVarList[i], pBcgPro->pUnpackTool->pBufferPack);
				}
				pBcgPro->pUnpackTool->pCurrentPack = 0;
				pBcgPro->pUnpackTool->currentLen = 0;
			}

		}
	}
//	return Type;
}
static int UnpackSingleVar(BcgVar* pBcgVar, unsigned char* pBufferPack)
{
	unsigned i,j,tempBitSeg,tempBit;
	int var=0;
	BcgPosSeg* pPos;
	for (i=0;i<pBcgVar->varPosSegNum;i++)
	{
		pPos = pBcgVar->pVarPosSeg + i;
		tempBitSeg = pBufferPack[pPos->bytePos] >> pPos->bitPosInByte;
		for (j=0;j<pPos->bitLen;j++)
		{
			tempBit = (tempBitSeg >> j) & 0x01;
			var |= tempBit << (j + pPos->bitPosInVar);
		}
	}
	return var;
}

static void	ResetBit7(unsigned char* pBufferPack)
{
	int i;
	for (i=2;i<BCG_PACK_LEN;i++)
	{	
		pBufferPack[i] &= 0x7f;
		pBufferPack[i] |= ((pBufferPack[1] >> (i-2)) & 0x01) << 7;
	}
}
static unsigned char CheckByteSum(unsigned char* pBufferPack)
{
	unsigned char flag = 0,i ;
	int sum = 0;
	for (i=0;i<BCG_PACK_LEN-1;i++)
	{
		sum += pBufferPack[i];
	}
	if ((sum&0x7f) == (pBufferPack[BCG_PACK_LEN-1]&0x7f))
		flag = 1;
	else
		flag = 0;
	return flag;

}

static BcgPack* ChosePack(BcgMod* pBcgMod, unsigned char* pBufferPack)
{
	unsigned char packID=0,i;
	BcgPack* pPack;
	for (i=0;i<pBcgMod->packNum;i++)
	{
		if (pBcgMod->pPackList[i]->packId == pBufferPack[2])
		{
			pPack = pBcgMod->pPackList[i];
			break;
		}
	}
	return pPack;
}




int GetVarVal(BcgMod* pBcgMod, unsigned char varType)
{
	int var;
	if (varType<pBcgMod->varNumInMod)
	{
		var = pBcgMod->pVarValListInMod[varType];
	}
	return var;
}
void SetVarVal(BcgMod* pBcgMod, unsigned char varType, int data)
{
	if (varType<pBcgMod->varNumInMod)
	{
		pBcgMod->pVarValListInMod[varType] = data;
	}
}