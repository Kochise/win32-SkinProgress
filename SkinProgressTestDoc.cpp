// SkinProgressTestDoc.cpp : implementation of the CSkinProgressTestDoc class
//

#include "stdafx.h"
#include "SkinProgressTest.h"

#include "SkinProgressTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestDoc

IMPLEMENT_DYNCREATE(CSkinProgressTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CSkinProgressTestDoc, CDocument)
	//{{AFX_MSG_MAP(CSkinProgressTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestDoc construction/destruction

CSkinProgressTestDoc::CSkinProgressTestDoc()
{
	// TODO: add one-time construction code here

}

CSkinProgressTestDoc::~CSkinProgressTestDoc()
{
}

BOOL CSkinProgressTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestDoc serialization

void CSkinProgressTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestDoc diagnostics

#ifdef _DEBUG
void CSkinProgressTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSkinProgressTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestDoc commands
