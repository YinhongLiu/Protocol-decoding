/*********************************************************************************************************
* 文件名称: BciData.h
* 文件作者: 
* 当前版本: 
* 所属模块: 
* 完成日期: 2014年07月12日
* 文件摘要: 
* 注意事项: 
* 更改说明: 
**********************************************************************************************************/
#ifndef _BCI_DATA_H_
#define _BCI_DATA_H_

/*********************************************************************************************************
*                                              枚举定义
*********************************************************************************************************/
//BCI数据
typedef enum
{
	BCI_DATA_SIGNAL_STRONG,		//信号强度
	BCI_DATA_SEARCH_LONG,		//搜索时间太长
	BCI_DATA_SENSOR_OFF,		//传感器脱落
	BCI_DATA_PULSE_BEAT,		//脉搏跳动
	BCI_DATA_PLETH_WAVE,		//体积描记波
	BCI_DATA_PULSE_RATE,		//脉率
	BCI_DATA_SPO2_VALUE,		//血氧值
	BCI_DATA_BAR_GRAPH,		//棒图
//	BCI_DATA_SENFOR_ERR,		//传感器错误
	BCI_DATA_SEARCH_PULSE,		//搜索脉搏
	BCI_DATA_MAX
}BciData;


/*********************************************************************************************************
*                                              API函数定义
*********************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
__declspec(dllexport) void InitBciData( void );
__declspec(dllexport) void SetBciData( int type, unsigned char bcidata );
__declspec(dllexport) void GetBciData( int type, unsigned char *pbcidata );
#ifdef __cplusplus
}
#endif

#endif

