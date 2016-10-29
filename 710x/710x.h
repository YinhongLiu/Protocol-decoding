#ifndef _710X_H_
#define _710X_H_
#include "datatype.h"
#define	_710X_PACK_LEN	9

typedef struct  
{
	u8	uVarPos;	//变量位置
	u8	uVarLen;	//变量长度
	u8	uByteNo;	//字节编号
	u8	uBytePos;	//字节位置
}_710xPos;

typedef struct  
{
	u8	uPosCnt;		//位置信息个数
	const _710xPos*	p710xPos;	//位置信息指针	
}_710xVar;

typedef struct  
{
	u8 uPackID;
	u8 uPackLen;
	u8 uVarCnt;
	i32 *pVarVal;
	const _710xVar** pPackVar;
}_710xPack;

typedef struct  
{
	u8* pPackBuf;
	u8 uCurrLen;
	const _710xPack* p710xPack;
}_710xUnpack;

typedef struct  
{
	u8 uPackCnt;
	i32 *pVarVal;
	u8 uVarCnt;
	const _710xPack** p710xPack;
	_710xUnpack*	p710xUnpack;
}_710xPro;


u8 Unpack710xData(_710xPro* p710xPro,u8 d);	//解析710x协议包数据
i32 Get710xData(_710xPro* p710xPro,u8 type);	//读710x解析结果数据
u8 Set710xData(_710xPro* p710xPro,u8 type,i32 data);	//设置710x结果数据
void Pack710xData(const _710xPack* p710xPack,u8* pPack);	//打包710x数据

#endif

