#include "710x.h"

static i32 Get710xVar(u8 *pPack,const _710xVar* pVar);//从数据包中取中指定变量
static void Set710xVar(u8 *pPack,const _710xVar* pVar);//将变量放入指定数据包中
static const _710xPack* Get710xPack(_710xPro* p710xPro,u8 pid);

u8 Unpack710xData(_710xPro* p710xPro,u8 d)
{
	u8 i,pid = 0;

	if(d < 0x80)
	{
		p710xPro->p710xUnpack->p710xPack = Get710xPack(p710xPro,d);
		if(p710xPro->p710xUnpack->p710xPack)
		{
			p710xPro->p710xUnpack->pPackBuf[0] = d;
			p710xPro->p710xUnpack->uCurrLen = 1;
		}
		else
		{
			p710xPro->p710xUnpack->uCurrLen = 0;
		}
	}
	else if(p710xPro->p710xUnpack->p710xPack)
	{
		p710xPro->p710xUnpack->pPackBuf[p710xPro->p710xUnpack->uCurrLen++] = d;
		if(p710xPro->p710xUnpack->uCurrLen == p710xPro->p710xUnpack->p710xPack->uPackLen)
		{
			for(i=2;i<p710xPro->p710xUnpack->p710xPack->uPackLen;i++)
			{
				p710xPro->p710xUnpack->pPackBuf[i] &= 0x7f;
				p710xPro->p710xUnpack->pPackBuf[i] |= ((p710xPro->p710xUnpack->pPackBuf[1]>>(i-2)) & 0x01) << 7;
			}

			for(i=0;i<p710xPro->p710xUnpack->p710xPack->uVarCnt;i++)
			{
				p710xPro->p710xUnpack->p710xPack->pVarVal[i] = Get710xVar(p710xPro->p710xUnpack->pPackBuf,p710xPro->p710xUnpack->p710xPack->pPackVar[i]);
			}
			
			p710xPro->p710xUnpack->p710xPack = 0;
			p710xPro->p710xUnpack->uCurrLen = 0;
			pid = p710xPro->p710xUnpack->pPackBuf[0];
		}
	}

	return pid;
}

i32 Get710xData(_710xPro* p710xPro,u8 type)
{
	i32 data = 0;

	if(type < p710xPro->uVarCnt)
	{
		data = p710xPro->pVarVal[type];
	}

	return data;
}

u8 Set710xData(_710xPro* p710xPro,u8 type,i32 data)
{
	return 0;
}

void Pack710xData(const _710xPack* p710xPack,u8* pPack)
{
}


static i32 Get710xVar(u8 *pPack,const _710xVar* pVar)
{
	const _710xPos* pPos;
	u8 i,j,tmp,bit0;
	i32 var = 0;

	for(i=0;i<pVar->uPosCnt;i++)
	{
		pPos = pVar->p710xPos+i;
		tmp = pPack[pPos->uByteNo] >> pPos->uBytePos;
		for(j=0;j<pPos->uVarLen;j++)
		{
			bit0 = (tmp >> j) & 0x01;
			var |= bit0 << (pPos->uVarPos + j);
		}
	}

	return var;
}

static void Set710xVar(u8 *pPack,const _710xVar* pVar)
{
}

static const _710xPack* Get710xPack(_710xPro* p710xPro,u8 pid)
{
	u8 i;
	const _710xPack* p = 0;

	for(i=0;i<p710xPro->uPackCnt;i++)
	{
		if(pid == p710xPro->p710xPack[i]->uPackID)
			p = p710xPro->p710xPack[i];
	}

	return p;
}