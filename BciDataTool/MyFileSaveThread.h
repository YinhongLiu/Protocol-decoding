// MyFileSaveThread.h: interface for the CMyFileSaveThread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYFILESAVETHREAD_H__33F6EDC0_5819_44B3_B8D0_2A478DFD9060__INCLUDED_)
#define AFX_MYFILESAVETHREAD_H__33F6EDC0_5819_44B3_B8D0_2A478DFD9060__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyWorkThread.h"

class AFX_EXT_CLASS CMyFileSaveThread : public CMyWorkThread  
{
public:
	CMyFileSaveThread();
	virtual ~CMyFileSaveThread();

	virtual void WorkThread();
	void ShowDlg();
public:
	CFile		m_File;
	BOOL		m_bSaveFile;
private:	
	void*		m_pDlg;

};

#endif // !defined(AFX_MYFILESAVETHREAD_H__33F6EDC0_5819_44B3_B8D0_2A478DFD9060__INCLUDED_)
