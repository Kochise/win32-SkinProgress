// SkinProgressTestView.h : interface of the CSkinProgressTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKINPROGRESSTESTVIEW_H__F4E6A6FA_37F3_4A97_BF39_0044C1F6A876__INCLUDED_)
#define AFX_SKINPROGRESSTESTVIEW_H__F4E6A6FA_37F3_4A97_BF39_0044C1F6A876__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainFrm.h"

class CSkinProgressTestView : public CFormView
{
protected: // create from serialization only
	CSkinProgressTestView();
	DECLARE_DYNCREATE(CSkinProgressTestView)

public:
	//{{AFX_DATA(CSkinProgressTestView)
	enum { IDD = IDD_SKINPROGRESSTEST_FORM };
	CStatic         m_cHeadReverse;
	CButton         m_cCheckReverse;
	CButton         m_cButtonDialog;
	CStatic         m_cPane4;
	CStatic         m_cPane3;
	CStatic         m_cPane2;
	CStatic         m_cPane1;
	CStatic         m_cPane0;
	CStatic         m_cBottomRight;
	CComboBox       m_cProgress;
	CSpinButtonCtrl	m_cSize;
	CSpinButtonCtrl	m_cPane;
	CSpinButtonCtrl	m_cLimit;
	CButton         m_cButtonTest;
	int             m_nLimit;
	int             m_nPane;
	int             m_nSize;
	CString         m_strText;
	BOOL            m_bCheckReverse;
	//}}AFX_DATA

// Attributes
public:
	CSkinProgressTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinProgressTestView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSkinProgressTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
  CSkinProgress* m_poSkinProgress; // The object within

// Generated message map functions
protected:
	//{{AFX_MSG(CSkinProgressTestView)
	afx_msg void OnButtonTest();
	afx_msg void OnRadioDefault();
	afx_msg void OnRadioAqua();
	afx_msg void OnRadioLuna();
	afx_msg void OnRadioPhoton();
	afx_msg void OnSize(UINT nType, int cx, int cy);
#ifdef dCSP_DIALOG_PROGRESS
	afx_msg void OnButtonDialog();
#endif // dCSP_DIALOG_PROGRESS
	afx_msg void OnSelchangeComboProgress();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SkinProgressTestView.cpp
inline CSkinProgressTestDoc* CSkinProgressTestView::GetDocument()
   { return (CSkinProgressTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINPROGRESSTESTVIEW_H__F4E6A6FA_37F3_4A97_BF39_0044C1F6A876__INCLUDED_)
