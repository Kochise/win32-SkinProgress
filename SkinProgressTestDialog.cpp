// SkinProgressTestDialog.cpp : implementation file
//

#include "stdafx.h"
#include "skinprogresstest.h"
#include "SkinProgressTestDialog.h"
#include "SkinProgressTestScanned.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestDialog dialog

#ifdef dCSP_DIALOG_PROGRESS

CSkinProgressTestDialog::CSkinProgressTestDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSkinProgressTestDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSkinProgressTestDialog)
	m_nLimit = 30000;
	m_strText = _T("This text allows to test the text wrapping");
	m_bCheckReverse = FALSE;
	//}}AFX_DATA_INIT

  m_poSkinProgress = NULL;

  // Minimum dialog size
  m_nWidth  = 0;
  m_nHeight = 0;
}


void CSkinProgressTestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSkinProgressTestDialog)
	DDX_Control(pDX, IDC_ICON_GRIP_SIZE, m_cGripSize);
	DDX_Control(pDX, IDC_HEAD_T1, m_cHeadT1);
	DDX_Control(pDX, IDC_HEAD_P1, m_cHeadP1);
	DDX_Control(pDX, IDC_CHECK_REVERSE, m_cCheckReverse);
	DDX_Control(pDX, IDC_HEAD_REVERSE, m_cHeadReverse);
	DDX_Control(pDX, IDC_EDIT_TEXT, m_cEditTxt);
	DDX_Control(pDX, IDC_COMA_TXT, m_cComaTxt);
	DDX_Control(pDX, IDC_COMA_TXTWND, m_cComaTxtWnd);
	DDX_Control(pDX, IDC_HEAD_PROGRESS, m_cHeadProgress);
	DDX_Control(pDX, IDC_HEAD_TXT, m_cHeadTxt);
	DDX_Control(pDX, IDC_HEAD_TXTWND, m_cHeadTxtWnd);
	DDX_Control(pDX, IDC_SPIN_LIMIT, m_cLimit);
	DDX_Control(pDX, IDC_COMBO_BAR, m_cBar);
	DDX_Control(pDX, IDC_COMBO_TEXT, m_cText);
	DDX_Control(pDX, IDC_COMBO_PROGRESS, m_cProgress);
	DDX_Control(pDX, IDC_BUTTON_TEST, m_cButtonTest);
	DDX_Control(pDX, IDC_BOTTOM_RIGHT, m_cBottomRight);
	DDX_Control(pDX, IDC_PROGRESS_2, m_cProgress2);
	DDX_Control(pDX, IDC_TEXTPANE_2, m_cTextPane2);
	DDX_Control(pDX, IDC_PROGRESS_1, m_cProgress1);
	DDX_Control(pDX, IDC_TEXTPANE_1, m_cTextPane1);
	DDX_Check(pDX, IDC_CHECK_REVERSE, m_bCheckReverse);
	DDX_Text(pDX, IDC_EDIT_LIMIT, m_nLimit);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strText);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSkinProgressTestDialog, CDialog)
	//{{AFX_MSG_MAP(CSkinProgressTestDialog)
	ON_BN_CLICKED(IDC_BUTTON_TEST, OnButtonTest)
	ON_BN_CLICKED(IDC_RADIO_DEFAULT, OnRadioDefault)
	ON_BN_CLICKED(IDC_RADIO_AQUA, OnRadioAqua)
	ON_BN_CLICKED(IDC_RADIO_LUNA, OnRadioLuna)
	ON_BN_CLICKED(IDC_RADIO_PHOTON, OnRadioPhoton)
	ON_WM_SIZE()
	ON_WM_SIZING()
	ON_CBN_SELCHANGE(IDC_COMBO_TEXT, OnSelchangeComboText)
	ON_BN_CLICKED(ID_SCANNED_SKIN, OnScannedSkin)
	ON_BN_CLICKED(IDC_SCANSKIN, OnScannedSkin)
	ON_CBN_SELCHANGE(IDC_COMBO_PROGRESS, OnSelchangeComboProgress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSkinProgressTestDialog::OnInitDialog() 
{

  // Init

  // Process

	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

  // Select IDC_PROGRESS_1
  m_cBar.SetCurSel(0);

  // Select Limit
  m_cLimit.SetRange32(1, 65535);
  m_cLimit.SetPos(30000);

  // Select default bitmap
  CheckRadioButton(IDC_RADIO_DEFAULT, IDC_RADIO_PHOTON, IDC_RADIO_DEFAULT);

  // Don't reverse the bitmap
  m_bCheckReverse = false;

  // Select IDC_TEXTPANE_1
  m_cText.SetCurSel(1);

  // Select AUTOSIZE
  m_cProgress.SetCurSel(6);

#ifdef dCSP_SLIDERBAR_METHOD
  m_cHeadReverse.EnableWindow(true);
  m_cCheckReverse.EnableWindow(true);
#else
  m_cHeadReverse.EnableWindow(false);
  m_cCheckReverse.EnableWindow(false);
#endif // dCSP_SLIDERBAR_METHOD

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestDialog message handlers

void CSkinProgressTestDialog::OnButtonTest() 
{
  CWnd*    poProgress = NULL;
  CBitmap* poBitmap   = NULL;
  CWnd*    poMessage  = NULL;
  int      nTempo;

	// TODO: Add your control notification handler code here
  UpdateData(true); // Update variables
  m_cButtonTest.EnableWindow(false); // Disable the 'TEST' button

  // Select the progress pane
  nTempo = m_cBar.GetCurSel();
  switch(nTempo)
  {
    case 0 :
      poProgress = &m_cProgress1;
      break;
    case 1 :
      poProgress = &m_cProgress2;
      break;
    default :
      poProgress = &m_cProgress1;
      break;
  }

  // Select the bitmap
  int nCheckedRadio = GetCheckedRadioButton(IDC_RADIO_DEFAULT, IDC_RADIO_PHOTON);
  switch(nCheckedRadio)
  {
    case IDC_RADIO_DEFAULT :
      poBitmap = NULL;
      break;
    case IDC_RADIO_AQUA :
      poBitmap = new CBitmap();
      poBitmap->LoadBitmap(IDB_BMP_AQUA);
      break;
    case IDC_RADIO_LUNA :
      poBitmap = new CBitmap();
      poBitmap->LoadBitmap(IDB_BMP_LUNA);
      break;
    case IDC_RADIO_PHOTON :
      poBitmap = new CBitmap();
      poBitmap->LoadBitmap(IDB_BMP_PHOTON);
      break;
    default :
      poBitmap = NULL;
      break;
  }

  // Select the text pane
  nTempo = m_cText.GetCurSel();
  switch(nTempo)
  {
    case 0 :
      poMessage = NULL;
      break;
    case 1 :
      poMessage = &m_cTextPane1;
      break;
    case 2 :
      poMessage = &m_cTextPane2;
      break;
    default :
      poMessage = NULL;
      break;
  }

#ifdef dCSP_DIALOG_PROGRESS
  { // Pointer living CSkinProgress demonstration
    if(poMessage != NULL)
    { // WITH TEXT
      m_poSkinProgress = new CSkinProgress
      (
        poProgress,
        m_nLimit,
        poBitmap,
#ifdef dCSP_SLIDERBAR_METHOD
        m_bCheckReverse,
#endif // dCSP_SLIDERBAR_METHOD
        poMessage,
        m_strText,
        m_cProgress.GetCurSel() - (cSPT_EnumElements - 1)
      );
    }
    else
    { // WITHOUT TEXT
      m_poSkinProgress = new CSkinProgress
      (
        poProgress,
        m_nLimit,
        poBitmap
#ifdef dCSP_SLIDERBAR_METHOD
       ,m_bCheckReverse
#endif // dCSP_SLIDERBAR_METHOD
      );
    }

/*
// dCSP_TIMED_REDRAW test purpose
    SYSTEMTIME     TimeIn;
    FILETIME       TimeOut;
   
    ULARGE_INTEGER TimeOne;
    ULARGE_INTEGER TimeTwo;

    GetLocalTime(&TimeIn);
    SystemTimeToFileTime(&TimeIn, &TimeOut);
    TimeOne.QuadPart   = TimeOut.dwHighDateTime;
    TimeOne.QuadPart <<= 32;
    TimeOne.QuadPart  |= TimeOut.dwLowDateTime;
*/

	  for(int i = 0; i < m_nLimit; i += 1)
    {

/*
// dCSP_TIMED_REDRAW test purpose
      TimeOne.QuadPart += 5;

      do
      {
        GetLocalTime(&TimeIn);
        SystemTimeToFileTime(&TimeIn, &TimeOut);
        TimeTwo.QuadPart   = TimeOut.dwHighDateTime;
        TimeTwo.QuadPart <<= 32;
        TimeTwo.QuadPart  |= TimeOut.dwLowDateTime;

      }
      while(TimeTwo.QuadPart < TimeOne.QuadPart);
      TimeOne = TimeTwo;
*/

	    m_poSkinProgress->StepIt();
	    PeekAndPump();
	  }

    delete m_poSkinProgress;
    m_poSkinProgress = NULL;
  } // Here the CSkinProgress is deleted
#endif // dCSP_DIALOG_PROGRESS

  if(poBitmap != NULL)
  {
    delete poBitmap;
  }else{}  

  if(IsWindow(m_cButtonTest.m_hWnd))
  { // If you close the application while the bar is in progress, the objects are already deleted, so avoid to enable a deleted object
    m_cButtonTest.EnableWindow(true); 
  }else{}
}

void CSkinProgressTestDialog::OnRadioDefault() 
{ // Set the Default bitmap
//  CheckRadioButton(IDC_RADIO_DEFAULT, IDC_RADIO_PHOTON, IDC_RADIO_DEFAULT);

  if(m_poSkinProgress != NULL)
  {
    m_poSkinProgress->SetBitmap(); // Default biptmap
  }else{}
}

void CSkinProgressTestDialog::OnRadioAqua() 
{ // Set the AQUA bitmap
//  CheckRadioButton(IDC_RADIO_DEFAULT, IDC_RADIO_PHOTON, IDC_RADIO_AQUA);

  if(m_poSkinProgress != NULL)
  {
    CBitmap oBitmap;
    oBitmap.LoadBitmap(IDB_BMP_AQUA);

    m_poSkinProgress->SetBitmap(&oBitmap);
  }else{}
}

void CSkinProgressTestDialog::OnRadioLuna() 
{ // Set the LUNA bitmap
//  CheckRadioButton(IDC_RADIO_DEFAULT, IDC_RADIO_PHOTON, IDC_RADIO_LUNA);

  if(m_poSkinProgress != NULL)
  {
    CBitmap oBitmap;
    oBitmap.LoadBitmap(IDB_BMP_LUNA);

    m_poSkinProgress->SetBitmap(&oBitmap);
  }else{}
}

void CSkinProgressTestDialog::OnRadioPhoton() 
{ // Set the PHOTON bitmap
//  CheckRadioButton(IDC_RADIO_DEFAULT, IDC_RADIO_PHOTON, IDC_RADIO_PHOTON);

  if(m_poSkinProgress != NULL)
  {
    CBitmap oBitmap;
    oBitmap.LoadBitmap(IDB_BMP_PHOTON);

    m_poSkinProgress->SetBitmap(&oBitmap);
  }else{}
}

void CSkinProgressTestDialog::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here

  CRect oRectPane;

  if(
         (m_nWidth  == 0)
      && (m_nHeight == 0)
    )
  { // Snap the start size of the dialog, quite messy, don't tell me please ;P
    m_nWidth  = cx + 8;  //  8 : Dummy value
    m_nHeight = cy + 27; // 27 : Dummy value
  }

  if(IsWindow(GetSafeHwnd()))
  {
    if(m_cProgress1.m_hWnd != NULL)
    { // Move the PROGRESS_1 pane
      m_cProgress1.GetWindowRect(oRectPane);
      this->ScreenToClient(oRectPane);
      oRectPane.right  = cx - 10; // 10 : Dummy value
      oRectPane.top    = cy - 62; // 62 : Dummy value
      oRectPane.bottom = cy - 42; // 42 : Dummy value
      m_cProgress1.MoveWindow(oRectPane); // , false); // Don't refresh right now, but wait complete update below
    }else{}

    if(m_cProgress2.m_hWnd != NULL)
    { // Resize the PROGRESS_2 pane
      m_cProgress2.GetWindowRect(oRectPane);
      this->ScreenToClient(oRectPane);
      oRectPane.bottom = cy - 72; // 72 : Dummy value
      m_cProgress2.MoveWindow(oRectPane); // , false); // Don't refresh right now, but wait complete update below
    }else{}

    if(m_cTextPane1.m_hWnd != NULL)
    {  // Move the TEXT_1 pane
      m_cTextPane1.GetWindowRect(oRectPane);
      this->ScreenToClient(oRectPane);
      oRectPane.right  = cx - 34; // 34 : Dummy value
      oRectPane.top    = cy - 33; // 33 : Dummy value
      oRectPane.bottom = cy - 13; // 13 : Dummy value
      m_cTextPane1.MoveWindow(oRectPane); // , false); // Don't refresh right now, but wait complete update below
    }else{}

    if(m_cTextPane2.m_hWnd != NULL)
    { // Resize the TEXT_2 pane
      m_cTextPane2.GetWindowRect(oRectPane);
      this->ScreenToClient(oRectPane);
      oRectPane.right  = cx - 10; // 10 : Dummy value
      oRectPane.bottom = cy - 71; // 71 : Dummy value
      m_cTextPane2.MoveWindow(oRectPane); // , false); // Don't refresh right now, but wait complete update below
    }else{}

    if(m_cHeadP1.m_hWnd != NULL)
    {  // Move the P_1 text
      m_cHeadP1.GetWindowRect(oRectPane);
      this->ScreenToClient(oRectPane);
      oRectPane.top    = cy - 62; // 62 : Dummy value
      oRectPane.bottom = cy - 42; // 42 : Dummy value
      m_cHeadP1.MoveWindow(oRectPane); // , false); // Don't refresh right now, but wait complete update below
    }else{}

    if(m_cHeadT1.m_hWnd != NULL)
    {  // Move the T_1 text
      m_cHeadT1.GetWindowRect(oRectPane);
      this->ScreenToClient(oRectPane);
      oRectPane.top    = cy - 33; // 33 : Dummy value
      oRectPane.bottom = cy - 13; // 13 : Dummy value
      m_cHeadT1.MoveWindow(oRectPane); // , false); // Don't refresh right now, but wait complete update below
    }else{}

    if(m_cGripSize.m_hWnd != NULL)
    {  // Move the size grip
      m_cGripSize.GetWindowRect(oRectPane);
      this->ScreenToClient(oRectPane);
      oRectPane.left   = cx - 32;
      oRectPane.right  = cx;
      oRectPane.top    = cy - 32;
      oRectPane.bottom = cy;
      m_cGripSize.MoveWindow(oRectPane); // , false); // Don't refresh right now, but wait complete update below
    }else{}
  }else{}

//  Invalidate(); // Invalidate everything -> Everything have to be updated
//  UpdateWindow(); // Update invalidated things (everything) -> FLASHY
}

void CSkinProgressTestDialog::OnSizing(UINT fwSide, LPRECT pRect) 
{ // Class Wizard -> Class Info tab -> Advanced options pane -> Message filter combo -> Window
	CDialog::OnSizing(fwSide, pRect);
	// TODO: Add your message handler code here and/or call default

  // Block horizontal
  if(
        (pRect->right - pRect->left)
      < m_nWidth
    )
  {
    if(
           (fwSide == WMSZ_BOTTOMLEFT)
        || (fwSide == WMSZ_LEFT)
        || (fwSide == WMSZ_TOPLEFT)
      )
    {
      pRect->left = pRect->right - m_nWidth;
    }
    else
    {
      pRect->right = pRect->left + m_nWidth;
    }
  }

  // Block vertical
  if(
        (pRect->bottom - pRect->top)
      < m_nHeight
    )
  {
    if(
           (fwSide == WMSZ_TOP)
        || (fwSide == WMSZ_TOPLEFT)
        || (fwSide == WMSZ_TOPRIGHT)
      )
    {
      pRect->top = pRect->bottom - m_nHeight;
    }
    else
    {
      pRect->bottom = pRect->top + m_nHeight;
    }
  }

  // Refresh the progress bar and the text pane
  if(m_poSkinProgress != NULL)
  {
    m_poSkinProgress->RefreshPanes();
  }else{}
}

void CSkinProgressTestDialog::OnSelchangeComboText() 
{
	// TODO: Add your control notification handler code here
  int      nTempo;

  // Disable/enable additional text parameters if text disabled/enabled
  nTempo = m_cText.GetCurSel();
  switch(nTempo)
  {
    case 0 :
      m_cHeadTxtWnd.EnableWindow(false);
      m_cComaTxtWnd.EnableWindow(false);
      m_cHeadTxt.EnableWindow(false);
      m_cEditTxt.EnableWindow(false);
      m_cComaTxt.EnableWindow(false);
      m_cHeadProgress.EnableWindow(false);
      m_cProgress.EnableWindow(false);
      break;
    default :
      m_cHeadTxtWnd.EnableWindow(true);
      m_cComaTxtWnd.EnableWindow(true);
      m_cHeadTxt.EnableWindow(true);
      m_cEditTxt.EnableWindow(true);
      m_cComaTxt.EnableWindow(true);
      m_cHeadProgress.EnableWindow(true);
      m_cProgress.EnableWindow(true);
      break;
  }
}

void CSkinProgressTestDialog::OnSelchangeComboProgress() 
{
	// TODO: Add your control notification handler code here
	if(m_poSkinProgress != NULL)
  {
    m_poSkinProgress->SetProgress(m_cProgress.GetCurSel() - (cSPT_EnumElements - 1));
  }else{}
}

void CSkinProgressTestDialog::OnScannedSkin() 
{
	// TODO: Add your control notification handler code here
  // Open the dialog
  CSkinProgressTestScanned ScannedDialog;

  ScannedDialog.DoModal();
}

#endif // dCSP_DIALOG_PROGRESS
