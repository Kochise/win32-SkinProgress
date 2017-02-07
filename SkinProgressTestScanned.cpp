// SkinProgressTestScanned.cpp : implementation file
//

#include "stdafx.h"
#include "skinprogresstest.h"
#include "SkinProgressTestScanned.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestScanned dialog

#ifdef dCSP_DIALOG_PROGRESS

CSkinProgressTestScanned::CSkinProgressTestScanned(CWnd* pParent /*=NULL*/)
	: CDialog(CSkinProgressTestScanned::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSkinProgressTestScanned)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CSkinProgressTestScanned::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSkinProgressTestScanned)
	DDX_Control(pDX, IDOK, m_cButtonOk);
	DDX_Control(pDX, IDC_THERMO, m_cStaticThermo);
	DDX_Control(pDX, IDC_PEN, m_cStaticPencil);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSkinProgressTestScanned, CDialog)
	//{{AFX_MSG_MAP(CSkinProgressTestScanned)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestScanned message handlers

/*

*/

void CSkinProgressTestScanned::OnOK() 
{
  m_cButtonOk.EnableWindow(false);

	// TODO: Add extra validation here

  int nMultiplyDelay = 100000; // 100000 : Dummy value, sorry, I've got a super strong computer
  // It's also nice to test the <dCSP_TIMED_REDRAW> mode

  //

  CBitmap oBitmapThermo;
  CBitmap oBitmapPencil;

  // Init

  oBitmapThermo.LoadBitmap(IDB_BMP_THERMO);
  oBitmapPencil.LoadBitmap(IDB_BMP_PENCIL);

  CSkinProgress oProgressThermo
  (
    &m_cStaticThermo,
    11 * nMultiplyDelay, // 11 for not overwrite the end element of the thermometer
    &oBitmapThermo
  );
  
  CSkinProgress oProgressPencil
  (
    &m_cStaticPencil,
    10 * nMultiplyDelay,
    &oBitmapPencil
  );

  oProgressPencil.SetPos(10 * nMultiplyDelay);
  oProgressPencil.SetStep(-1);
  
  // 

	for(int i = 0; i < 10 * nMultiplyDelay; i += 1)
  {
	  oProgressThermo.StepIt();
	  oProgressPencil.StepIt();
	  PeekAndPump();
	}

  m_cButtonOk.EnableWindow(true);
	
	CDialog::OnOK(); // Quit
}

#endif // dCSP_DIALOG_PROGRESS
