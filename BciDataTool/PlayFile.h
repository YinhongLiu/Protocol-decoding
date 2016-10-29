#if !defined(AFX_PLAYFILE_H__86BA2BB5_EB83_40E0_AAD0_8DBDE51C3C6A__INCLUDED_)
#define AFX_PLAYFILE_H__86BA2BB5_EB83_40E0_AAD0_8DBDE51C3C6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PlayFile.h : header file
//

#define	WM_FILE_PLAY_REFRESH	WM_USER+8001
/////////////////////////////////////////////////////////////////////////////
// CPlayFile window
#define	MAX_DATA_CHANNEL	3

class AFX_EXT_CLASS CPlayFile : public CObject
{
// Construction
public:
	CPlayFile();

// Attributes
public:
	CString	m_strPath;
	CString m_strFileName;
	CString	m_strFileType;
	UINT	m_nFileSize;
	UINT	m_nCurPos;
	UINT	m_nChannels;
	VOID	*m_pData[MAX_DATA_CHANNEL];
	CWnd*	m_pOwner;
	void*	m_pDlg;
	//BOOL	m_bStaticPlay;

// Operations
public:
	void ShowDlg();
	void RealseDataMem();
	void ReadDataFile();

private:
	void Init();
	void ReadBinDataFile();
	void ReadDatDataFile();
// Implementation
public:
	virtual ~CPlayFile();

	// Generated message map functions
protected:

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYFILE_H__86BA2BB5_EB83_40E0_AAD0_8DBDE51C3C6A__INCLUDED_)
