#if !defined(AFX_SKINPROGRESSTESTSCANNED_H__CCFB2EDE_E3B0_4FC4_9BD5_A38149DFA5F3__INCLUDED_)
#define AFX_SKINPROGRESSTESTSCANNED_H__CCFB2EDE_E3B0_4FC4_9BD5_A38149DFA5F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainFrm.h"

// SkinProgressTestScanned.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestScanned dialog

class CSkinProgressTestScanned : public CDialog
{
// Construction
public:
	CSkinProgressTestScanned(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSkinProgressTestScanned)
	enum { IDD = IDD_SCANNED_SKIN };
	CButton	m_cButtonOk;
	CStatic	m_cStaticThermo;
	CStatic	m_cStaticPencil;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinProgressTestScanned)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSkinProgressTestScanned)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINPROGRESSTESTSCANNED_H__CCFB2EDE_E3B0_4FC4_9BD5_A38149DFA5F3__INCLUDED_)
