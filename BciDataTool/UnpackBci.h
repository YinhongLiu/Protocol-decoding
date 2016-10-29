// UnpackBci.h: interface for the CUnpackBci class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNPACKBCI_H__1EAAFE89_CB4D_4B84_9319_27F277FA41C5__INCLUDED_)
#define AFX_UNPACKBCI_H__1EAAFE89_CB4D_4B84_9319_27F277FA41C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define BCI_PACK_LEN	5           //����

typedef enum
{
	BCI_DATA_SIGNAL_STRONG,		//�ź�ǿ��
		BCI_DATA_SEARCH_LONG,		//����ʱ��̫��
		BCI_DATA_SENSOR_OFF,		//����������
		BCI_DATA_PULSE_BEAT,		//��������
		BCI_DATA_PLETH_WAVE,		//�����ǲ�
		BCI_DATA_PULSE_RATE,		//����
		BCI_DATA_SPO2_VALUE,		//Ѫ��ֵ
		BCI_DATA_BAR_GRAPH,			//��ͼ
		//BCI_DATA_SENFOR_ERR,		//����������
		BCI_DATA_SEARCH_PULSE,		//��������
		BCI_DATA_MAX
}BciData;

class __declspec(dllexport) CUnpackBci  
{
public:
	CUnpackBci();
	virtual ~CUnpackBci();
	int	UnpackData(unsigned char d);			//����BCIЭ�����ݣ����ش���0��ʾ�ҵ�BCI������������û���ҵ�
	void GetBciData( int type, unsigned char *pbcidata );//��ȡBCI���������type��ʾ�������ͣ�����ʹ��BciDataö��ֵ����
private:
	unsigned char	m_cUartData[BCI_PACK_LEN];	//���ڽ������ݻ�����
	unsigned char	m_cBciData[BCI_DATA_MAX];	//BCIЭ������������
private:
	void InitBcipack(void);
	void SetBciData( int type, unsigned char bcidata );

};

#endif // !defined(AFX_UNPACKBCI_H__1EAAFE89_CB4D_4B84_9319_27F277FA41C5__INCLUDED_)
