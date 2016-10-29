#ifndef _710X_H_
#define _710X_H_
#include "datatype.h"
#define	_710X_PACK_LEN	9

typedef struct  
{
	u8	uVarPos;	//����λ��
	u8	uVarLen;	//��������
	u8	uByteNo;	//�ֽڱ��
	u8	uBytePos;	//�ֽ�λ��
}_710xPos;

typedef struct  
{
	u8	uPosCnt;		//λ����Ϣ����
	const _710xPos*	p710xPos;	//λ����Ϣָ��	
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


u8 Unpack710xData(_710xPro* p710xPro,u8 d);	//����710xЭ�������
i32 Get710xData(_710xPro* p710xPro,u8 type);	//��710x�����������
u8 Set710xData(_710xPro* p710xPro,u8 type,i32 data);	//����710x�������
void Pack710xData(const _710xPack* p710xPack,u8* pPack);	//���710x����

#endif

