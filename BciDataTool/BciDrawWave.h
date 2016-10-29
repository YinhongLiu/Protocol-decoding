// BciDrawWave.h : main header file for the BCIDRAWWAVE application
//

#if !defined(AFX_BCIDRAWWAVE_H__C3F25C1D_3824_4B9D_8352_A81478A904BD__INCLUDED_)
#define AFX_BCIDRAWWAVE_H__C3F25C1D_3824_4B9D_8352_A81478A904BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBciDrawWaveApp:
// See BciDrawWave.cpp for the implementation of this class
//

class CBciDrawWaveApp : public CWinApp
{
public:
	CBciDrawWaveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBciDrawWaveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBciDrawWaveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCIDRAWWAVE_H__C3F25C1D_3824_4B9D_8352_A81478A904BD__INCLUDED_)
