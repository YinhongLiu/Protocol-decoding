// BciDrawWaveDlg.h : header file
//

#if !defined(AFX_BCIDRAWWAVEDLG_H__69F1ED85_1BB0_4858_8D52_F53592036BF3__INCLUDED_)
#define AFX_BCIDRAWWAVEDLG_H__69F1ED85_1BB0_4858_8D52_F53592036BF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SerialPort.h"

#include "ProtocolPack.h"
#include "OScopeCtrl.h"
#include "MyFileSaveThread.h"
#include "ColorStatic.h"
#include "PlayFile.h"

#pragma comment(lib, "ProtocolDll")
#pragma comment(lib, "BciDll")
#pragma comment(lib, "ComSet")
#pragma comment(lib, "DrawWave")
#pragma comment(lib, "FileSave")
#pragma comment(lib, "CFilePlay")
/////////////////////////////////////////////////////////////////////////////
// CBciDrawWaveDlg dialog

class CBciDrawWaveDlg : public CDialog
{
// Construction
public:
	CBciDrawWaveDlg(CWnd* pParent = NULL);	// standard constructor

	CSerialPort m_SerialPort;
	COScopeCtrl m_OScopeCtrl;
	COScopeCtrl m_OSCopeInfraRedCtrl;
	CMyFileSaveThread m_FileSaveThread;
	CPlayFile m_PlayFile;

// Dialog Data
	//{{AFX_DATA(CBciDrawWaveDlg)
	enum { IDD = IDD_BCIDRAWWAVE_DIALOG };
	CColorStatic	m_ctrlSpo2;
	CColorStatic	m_ctrlPr;
	CColorStatic	m_ctrlBar;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBciDrawWaveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBciDrawWaveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonUartSet();
	afx_msg void OnButtonUartOpen();
	afx_msg void OnButtonUartClose();
	afx_msg void OnMessageCom(WPARAM wp,LPARAM lp);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonFileSave();
	afx_msg void OnButtonFileReview();
	afx_msg void OnPlayFile(WPARAM wp,LPARAM lp);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCIDRAWWAVEDLG_H__69F1ED85_1BB0_4858_8D52_F53592036BF3__INCLUDED_)
