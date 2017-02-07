#if !defined(AFX_SKINPROGRESSTESTDIALOG_H__CD963196_AA86_470F_8FD8_B6F273861D3C__INCLUDED_)
#define AFX_SKINPROGRESSTESTDIALOG_H__CD963196_AA86_470F_8FD8_B6F273861D3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainFrm.h"

// SkinProgressTestDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestDialog dialog

class CSkinProgressTestDialog : public CDialog
{
// Construction
public:
	CSkinProgressTestDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSkinProgressTestDialog)
	enum { IDD = IDD_SKINPROGRESSTEST_DIAL };
	CStatic         m_cGripSize;
	CStatic	        m_cHeadT1;
	CStatic	        m_cHeadP1;
	CButton         m_cCheckReverse;
	CStatic         m_cHeadReverse;
	CEdit           m_cEditTxt;
	CStatic         m_cComaTxt;
	CStatic         m_cComaTxtWnd;
	CStatic         m_cHeadProgress;
	CStatic         m_cHeadTxt;
	CStatic         m_cHeadTxtWnd;
	CSpinButtonCtrl m_cLimit;
	CComboBox       m_cBar;
	CComboBox       m_cText;
	CComboBox       m_cProgress;
	CButton         m_cButtonTest;
	CStatic         m_cBottomRight;
	CStatic         m_cProgress2;
	CStatic         m_cTextPane2;
	CStatic         m_cProgress1;
	CStatic         m_cTextPane1;
	BOOL            m_bCheckReverse;
	int             m_nLimit;
	CString         m_strText;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinProgressTestDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
  CSkinProgress* m_poSkinProgress; // The object within

  int m_nWidth;
  int m_nHeight;

	// Generated message map functions
	//{{AFX_MSG(CSkinProgressTestDialog)
	afx_msg void OnButtonTest();
	afx_msg void OnRadioDefault();
	afx_msg void OnRadioAqua();
	afx_msg void OnRadioLuna();
	afx_msg void OnRadioPhoton();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboText();
	afx_msg void OnScannedSkin();
	afx_msg void OnSelchangeComboProgress();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINPROGRESSTESTDIALOG_H__CD963196_AA86_470F_8FD8_B6F273861D3C__INCLUDED_)
