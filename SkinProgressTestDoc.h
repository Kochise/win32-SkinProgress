// SkinProgressTestDoc.h : interface of the CSkinProgressTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKINPROGRESSTESTDOC_H__A077BCB0_D609_4359_9BDA_DA37B3751232__INCLUDED_)
#define AFX_SKINPROGRESSTESTDOC_H__A077BCB0_D609_4359_9BDA_DA37B3751232__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSkinProgressTestDoc : public CDocument
{
protected: // create from serialization only
	CSkinProgressTestDoc();
	DECLARE_DYNCREATE(CSkinProgressTestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinProgressTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSkinProgressTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSkinProgressTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINPROGRESSTESTDOC_H__A077BCB0_D609_4359_9BDA_DA37B3751232__INCLUDED_)
