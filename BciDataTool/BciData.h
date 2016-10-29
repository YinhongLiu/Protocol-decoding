/*********************************************************************************************************
* �ļ�����: BciData.h
* �ļ�����: 
* ��ǰ�汾: 
* ����ģ��: 
* �������: 2014��07��12��
* �ļ�ժҪ: 
* ע������: 
* ����˵��: 
**********************************************************************************************************/
#ifndef _BCI_DATA_H_
#define _BCI_DATA_H_

/*********************************************************************************************************
*                                              ö�ٶ���
*********************************************************************************************************/
//BCI����
typedef enum
{
	BCI_DATA_SIGNAL_STRONG,		//�ź�ǿ��
	BCI_DATA_SEARCH_LONG,		//����ʱ��̫��
	BCI_DATA_SENSOR_OFF,		//����������
	BCI_DATA_PULSE_BEAT,		//��������
	BCI_DATA_PLETH_WAVE,		//�����ǲ�
	BCI_DATA_PULSE_RATE,		//����
	BCI_DATA_SPO2_VALUE,		//Ѫ��ֵ
	BCI_DATA_BAR_GRAPH,		//��ͼ
//	BCI_DATA_SENFOR_ERR,		//����������
	BCI_DATA_SEARCH_PULSE,		//��������
	BCI_DATA_MAX
}BciData;


/*********************************************************************************************************
*                                              API��������
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

