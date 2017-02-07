// SkinProgressTest.h : main header file for the SKINPROGRESSTEST application
//

#if !defined(AFX_SKINPROGRESSTEST_H__0EC4F43A_C6B0_46E1_8320_87C4D1A0DD68__INCLUDED_)
#define AFX_SKINPROGRESSTEST_H__0EC4F43A_C6B0_46E1_8320_87C4D1A0DD68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestApp:
// See SkinProgressTest.cpp for the implementation of this class
//

class CSkinProgressTestApp : public CWinApp
{
public:
	CSkinProgressTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinProgressTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSkinProgressTestApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINPROGRESSTEST_H__0EC4F43A_C6B0_46E1_8320_87C4D1A0DD68__INCLUDED_)
