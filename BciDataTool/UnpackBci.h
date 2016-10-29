// UnpackBci.h: interface for the CUnpackBci class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNPACKBCI_H__1EAAFE89_CB4D_4B84_9319_27F277FA41C5__INCLUDED_)
#define AFX_UNPACKBCI_H__1EAAFE89_CB4D_4B84_9319_27F277FA41C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define BCI_PACK_LEN	5           //包长

typedef enum
{
	BCI_DATA_SIGNAL_STRONG,		//信号强度
		BCI_DATA_SEARCH_LONG,		//搜索时间太长
		BCI_DATA_SENSOR_OFF,		//传感器脱落
		BCI_DATA_PULSE_BEAT,		//脉搏跳动
		BCI_DATA_PLETH_WAVE,		//体积描记波
		BCI_DATA_PULSE_RATE,		//脉率
		BCI_DATA_SPO2_VALUE,		//血氧值
		BCI_DATA_BAR_GRAPH,			//棒图
		//BCI_DATA_SENFOR_ERR,		//传感器错误
		BCI_DATA_SEARCH_PULSE,		//搜索脉搏
		BCI_DATA_MAX
}BciData;

class __declspec(dllexport) CUnpackBci  
{
public:
	CUnpackBci();
	virtual ~CUnpackBci();
	int	UnpackData(unsigned char d);			//解析BCI协议数据，返回大于0表示找到BCI完整包，否则没有找到
	void GetBciData( int type, unsigned char *pbcidata );//读取BCI解析结果，type表示数据类型，可以使用BciData枚举值代替
private:
	unsigned char	m_cUartData[BCI_PACK_LEN];	//串口接收数据缓冲区
	unsigned char	m_cBciData[BCI_DATA_MAX];	//BCI协议解析结果数组
private:
	void InitBcipack(void);
	void SetBciData( int type, unsigned char bcidata );

};

#endif // !defined(AFX_UNPACKBCI_H__1EAAFE89_CB4D_4B84_9319_27F277FA41C5__INCLUDED_)
