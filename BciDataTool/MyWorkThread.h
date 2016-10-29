// MyWorkThread.h: interface for the CMyWorkThread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYWORKTHREAD_H__23A98A08_E768_4D4B_92B3_BF6FABE8987E__INCLUDED_)
#define AFX_MYWORKTHREAD_H__23A98A08_E768_4D4B_92B3_BF6FABE8987E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS CMyWorkThread  
{
public:
	CMyWorkThread();
	virtual ~CMyWorkThread();
protected:
	VOID*		m_pWorkThread;
	BOOL		m_bStartThread;
	UCHAR*		m_pBuf;
	UINT		m_nBufSize;
	UINT		m_nReadPtr;
	UINT		m_nWritePtr;
	HANDLE	m_hDataEvent;
// Operations
public:
	virtual void WorkThread();
	virtual BOOL	SetBufLen(UINT nLen);
	virtual VOID	SatrtWorkThread();
	virtual VOID	StopWorkThread();
	virtual INT		ReceiveData(UCHAR *pBuf,UINT nCount);
	virtual BOOL	GetBufData(UCHAR &data);
};

#endif // !defined(AFX_MYWORKTHREAD_H__23A98A08_E768_4D4B_92B3_BF6FABE8987E__INCLUDED_)
