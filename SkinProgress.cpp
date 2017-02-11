/******************************************************************************/
/* NAME              : SkinProgress.cpp                                       */
/* PURPOSE           : Place a bitmapped progress bar into the status bar     */
/* CREATED_BY        : Kochise (kochise@caramail.com)                         */
/* CREATION_DATE     : $C_DATE=YYYY/MM/DD$ 2003/05/02                         */
/* MODIFIED_BY       : Kochise (kochise@caramail.com)                         */
/* MODIFICATION_DATE : $M_DATE=YYYY/MM/DD$ 2003/07/12                         */
/* LANGUAGE          : MFC Visual C++ 6                                       */
/* MPROC_TYPE        : Microsoft Windows compatible computer                  */
/*                                                                            */
/*

 *   Rev 1.03 : January 10 2005 14:01:53 (Kochise)

$Log: E:\Projects\NoeZooArc\SkinProgressTest.zoo\SkinProgressTest\SkinProgress.cpp.adiff $
 *
 *   Rev 1.02 : July 12 2003 14:01:53 (Kochise)
 * Base : CSkinProgress 1.32dev
 *   extracting files : no error
 *   parsing files : no error
 *   diff engine : no error
 *   modify.public.constructor:CSkinProgress
 *   touch.protected.function:CreateCommon
 *   modify.protected.function:ProgressInStatusBar
 *   modify.protected.function:ProgressInDialog
 *   modify.public.function:SetRange
 *   touch.public.function:SetPos
 *   modify.public.function:GetPos
 *   touch.public.function:SetStart
 *   modify.public.function:GetStart
 *   modify.public.function:Reset
 *   add.public.function:SetProgress
 *   add.public.function:GetProgress
 *   modify.public.function:RefreshPanes
 *   touch.protected.function:CompactText
 *   modify.protected.function:GetTimed
 *   modify.protected.function:UpdateProgress
 *   modify.protected.function:OnPaint
 *   compiling project files : no error
 *   packing files : no error
 * http://www.codeproject.com/miscctrl/CSkinProgress.asp
 *
 *   Rev 1.01 : July 06 2003 22:08:37 (Kochise)
 * Base : CSkinProgress 1.28 Devel
 *   extracting files : no error
 *   parsing files : no error
 *   diff engine : no error
 *   modify.public.constructor:CSkinProgress
 *   add.public.constructor:CSkinProgress
 *   modify.public.function:SetBitmap
 *   modify.public.function:ConvBitmap
 *   modify.public.function:SetRange
 *   modify.public.function:SetPos
 *   modify.public.function:OffsetPos
 *   modify.public.function:StepIt
 *   modify.public.function:SetSize
 *   add.public.function:GetSize
 *   add.public.function:GetPos
 *   add.public.function:GetStep
 *   add.public.function:GetLower
 *   add.public.function:GetUpper
 *   add.public.function:SetStart
 *   add.public.function:GetStart
 *   add.public.function:Reset
 *   modify.public.function:SetText
 *   mutate.function:protected.ResizeTextPane->public.RefreshPanes
 *   modify.public.function:RefreshPanes
 *   mutate.function:public.Clear->protected.Clear
 *   add.protected.function:GetTargetRect
 *   mutate.protected.function:Create->CreateCommon
 *   modify.protected.function:CreateCommon
 *   add.protected.function:ProgressInStatusBar
 *   add.protected.function:ProgressInDialog
 *   modify.protected.function:CompactText
 *   add.protected.function:UpdateProgress
 *   modify.protected.function:OnPaint
 *   compiling project files : no error
 *   packing files : no error
 * http://www.codeproject.com/miscctrl/CSkinProgress.asp
 *
 *   Rev 1.00 : May 25 2003 13:25:12 (Kochise)
 * First archived version and released onto CodeProject.
 * Base : CSkinProgress 1.12 Devel
 *   add.public.constructor:CSkinProgress
 *   add.public.constructor:CSkinProgress
 *   add.public.function:SetRange
 *   add.public.function:SetText
 *   add.public.function:SetSize
 *   add.public.function:SetBitmap
 *   add.public.function:CopyBitmap
 *   add.public.function:ConvBitmap
 *   add.public.function:SetPos
 *   add.public.function:OffsetPos
 *   add.public.function:SetStep
 *   add.public.function:StepIt
 *   add.public.function:Clear
 *   add.public.destructor:~CSkinProgress
 *   add.protected.function:Create
 *   add.protected.function:GetStatusBar
 *   add.protected.function:ResizeTextPane
 *   add.protected.function:CompactText
 *   add.protected.function:GetTimed
 *   add.protected.function:OnEraseBkgnd
 *   add.protected.function:OnPaint
 *   add.protected.function:OnSizing
 *   add.protected.function:OnSize
 *   add.protected.function:OnTimer
 *   compiling project files : no error
 *   packing files : no error
 * http://www.codeproject.com/useritems/CSkinProgress.asp
 *
 */
/******************************************************************************/

// SkinProgress.cpp : implementation file
//

#include "stdafx.h"
#include "SkinProgress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkinProgress

// g_Global      : g_ = Global
// i_Input       : i_ = Input
// no z...
// m_Member      : m_ = Member
// o_Output      : o_ = Output
// l_Local       : l_ = Local
// ...           : use your imagination

// aArray        : a  = Array    (array)
// bBool         : b  = Boolean  (boolean, TRUE/FALSE)
// cConstant     : c  = Constant (constant, whatever...)
// dDefine       : d  = Define   (simple define or defined value)
// eEnum         : e  = Enum     (enum list element)
// nNumber       : n  = Number   (char, long, int, whatever...)
// oObject       : o  = Object   (C++ class)
// pPointer      : p  = Pointer  (typicaly a 32 bits ulong address)
// sStruct       : s  = Struct   (structure)
// tTemplate     : t  = Template (template)
// uUnion        : u  = Union    (join two or more values of the same size under a common name)

// poRemoteClass : po = Pointer on Object
// cdConstantDef : cd = Constant Define, typicaly a constant defined value
// usUnionStruct : us = Union of Structures
// ...           : use your imagination

// o_psBitmap    : CBitmap::GetBitmap((BITMAP*) o_psBitmap); // s = BITMAP, p = *, o_ means it's an output

// <Value>
// [Function]

// TYPICAL LIFE TIME
// 
// USER   CSkinProgress(...) -----> StepIt() -----> ~CSkinProgress()
// SIDE     |                         |                |
// .........|.........................|................|.......................
//          |                         |                |
// OBJECT   '-> Create(...)           |                '-> _Clear()
// SIDE           |                   |
//                +-> _GetStatusBar() |
//                +-> SetRange(...)   |
//                +-> SetBitmap(...)  '->
//                '---------------------> RefreshPanes() ---------,
//                ,--------------------->   |                     |
//                |                 ,--->   |                     |
//                |                 |       |                     |
//                |                 |       +-> _GetStatusBar()   |
//                |                 |       +-> _GetTimed(...)    |
//                |                 |       '-> _CompactText(...) |
// ...............|.................|.............................|............
// WINDOWS        |                 |                             |
// SIDE         OnSizing(...)     OnEraseBkgnd(...)               '-> OnPaint()
//                |
//                '-> OnSize(...)

#ifndef dCSP_RESOURCE_BITMAP
/*** g_anAQUA_BITMAP **********************************************************/
/* Purpose : The default embedded progress bar image, if resource bitmap not  */
/*           used instead.                                                    */
/* Unit    : unsigned char                                                    */
/* Range   : [0-255] - LIMITED selection                                      */
/* List    : None                                                             */
/* Example : None                                                             */
/******************************************************************************/
unsigned char g_anAQUA_BITMAP[5760] =
{ // B,    G,    R,    A -> Set to 0xFF for CAlphaBlendBitmap
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xAC, 0x9C, 0x9B, 0xFF, 0x9F, 0x60, 0x5A, 0xFF, 0x9E, 0x38, 0x2B, 0xFF,
  0xA2, 0x22, 0x00, 0xFF, 0xAA, 0x22, 0x00, 0xFF, 0xAB, 0x2B, 0x00, 0xFF, 0xAB, 0x2B, 0x00, 0xFF,
  0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF,
  0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF,
  0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF,
  0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF,
  0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF,
  0xAB, 0x2B, 0x00, 0xFF, 0xB1, 0x33, 0x00, 0xFF, 0xAB, 0x38, 0x00, 0xFF, 0xA4, 0x46, 0x27, 0xFF,
  0x9E, 0x65, 0x54, 0xFF, 0x99, 0x89, 0x86, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xA9, 0x8A, 0x86, 0xFF, 0x9F, 0x40, 0x2E, 0xFF,
  0xA5, 0x1C, 0x00, 0xFF, 0xB1, 0x2E, 0x00, 0xFF, 0xC8, 0x6D, 0x42, 0xFF, 0xD8, 0x91, 0x67, 0xFF,
  0xDB, 0x9D, 0x76, 0xFF, 0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF,
  0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF,
  0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF,
  0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF,
  0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF,
  0xDD, 0xA2, 0x75, 0xFF, 0xDD, 0xA2, 0x75, 0xFF, 0xDB, 0x9D, 0x76, 0xFF, 0xD9, 0x94, 0x6D, 0xFF,
  0xC8, 0x6D, 0x42, 0xFF, 0xB1, 0x33, 0x00, 0xFF, 0xA5, 0x1C, 0x00, 0xFF, 0x97, 0x3D, 0x22, 0xFF,
  0x8E, 0x6F, 0x6B, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xB4, 0xA5, 0xA2, 0xFF,
  0xA1, 0x46, 0x2E, 0xFF, 0xAB, 0x2B, 0x00, 0xFF, 0xAF, 0x33, 0x00, 0xFF, 0xCE, 0x76, 0x42, 0xFF,
  0xE0, 0xAB, 0x81, 0xFF, 0xE5, 0xB5, 0x89, 0xFF, 0xE7, 0xBC, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF,
  0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF,
  0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF,
  0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF,
  0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF,
  0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF,
  0xE7, 0xBC, 0x95, 0xFF, 0xE5, 0xB5, 0x89, 0xFF, 0xE3, 0xAF, 0x88, 0xFF, 0xD0, 0x7F, 0x4C, 0xFF,
  0xB1, 0x33, 0x00, 0xFF, 0xAB, 0x2B, 0x00, 0xFF, 0x97, 0x3D, 0x22, 0xFF, 0x88, 0x78, 0x76, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xA6, 0x6E, 0x5A, 0xFF, 0xAF, 0x33, 0x00, 0xFF, 0xB8, 0x3D, 0x00, 0xFF,
  0xBB, 0x45, 0x00, 0xFF, 0xD4, 0x87, 0x44, 0xFF, 0xE4, 0xAD, 0x7B, 0xFF, 0xE5, 0xB3, 0x84, 0xFF,
  0xE5, 0xB5, 0x89, 0xFF, 0xE6, 0xB8, 0x8C, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF,
  0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF,
  0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF,
  0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF,
  0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF,
  0xE9, 0xBD, 0x95, 0xFF, 0xE9, 0xBD, 0x95, 0xFF, 0xE6, 0xB8, 0x8C, 0xFF, 0xE5, 0xB3, 0x84, 0xFF,
  0xE4, 0xAD, 0x7B, 0xFF, 0xD8, 0x8E, 0x4E, 0xFF, 0xBB, 0x45, 0x00, 0xFF, 0xB8, 0x3D, 0x00, 0xFF,
  0xB1, 0x33, 0x00, 0xFF, 0x89, 0x50, 0x3D, 0xFF, 0x99, 0x99, 0x99, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF,
  0xCD, 0xCD, 0xCD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF, 0xA6, 0x50, 0x27, 0xFF,
  0xBB, 0x45, 0x00, 0xFF, 0xBF, 0x4E, 0x00, 0xFF, 0xC1, 0x54, 0x00, 0xFF, 0xD4, 0x7A, 0x2E, 0xFF,
  0xE1, 0xA2, 0x6A, 0xFF, 0xE5, 0xAC, 0x77, 0xFF, 0xE7, 0xB1, 0x7F, 0xFF, 0xE9, 0xB4, 0x85, 0xFF,
  0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF,
  0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF,
  0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF,
  0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF,
  0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF, 0xE9, 0xB6, 0x88, 0xFF,
  0xE5, 0xB3, 0x84, 0xFF, 0xE4, 0xAD, 0x7B, 0xFF, 0xE1, 0xA6, 0x72, 0xFF, 0xD4, 0x80, 0x38, 0xFF,
  0xC1, 0x54, 0x00, 0xFF, 0xBF, 0x4E, 0x00, 0xFF, 0xBB, 0x45, 0x00, 0xFF, 0x9B, 0x46, 0x1C, 0xFF,
  0x82, 0x82, 0x82, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xB6, 0x4C, 0x00, 0xFF, 0xC1, 0x54, 0x00, 0xFF, 0xC5, 0x5C, 0x00, 0xFF,
  0xCA, 0x63, 0x15, 0xFF, 0xD4, 0x73, 0x22, 0xFF, 0xD9, 0x7D, 0x2E, 0xFF, 0xDA, 0x84, 0x3B, 0xFF,
  0xDF, 0x8A, 0x42, 0xFF, 0xE0, 0x8D, 0x48, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF,
  0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF,
  0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF,
  0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF,
  0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF,
  0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE0, 0x8D, 0x48, 0xFF, 0xDA, 0x84, 0x3B, 0xFF,
  0xD4, 0x7A, 0x2E, 0xFF, 0xCE, 0x6F, 0x22, 0xFF, 0xC5, 0x61, 0x15, 0xFF, 0xC5, 0x5C, 0x00, 0xFF,
  0xB8, 0x55, 0x00, 0xFF, 0xB6, 0x4C, 0x00, 0xFF, 0x73, 0x73, 0x73, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xD5, 0xD5, 0xD5, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xB6, 0x4C, 0x00, 0xFF,
  0xC1, 0x54, 0x00, 0xFF, 0xC5, 0x5C, 0x00, 0xFF, 0xCA, 0x63, 0x15, 0xFF, 0xD4, 0x73, 0x22, 0xFF,
  0xD9, 0x7D, 0x2E, 0xFF, 0xDA, 0x84, 0x3B, 0xFF, 0xDF, 0x8A, 0x42, 0xFF, 0xE0, 0x8D, 0x48, 0xFF,
  0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF,
  0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF,
  0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF,
  0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF,
  0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF, 0xE5, 0x94, 0x4D, 0xFF,
  0xE0, 0x8D, 0x48, 0xFF, 0xDA, 0x84, 0x3B, 0xFF, 0xD4, 0x7A, 0x2E, 0xFF, 0xCE, 0x6F, 0x22, 0xFF,
  0xC5, 0x61, 0x15, 0xFF, 0xC5, 0x5C, 0x00, 0xFF, 0xB8, 0x55, 0x00, 0xFF, 0xB6, 0x4C, 0x00, 0xFF,
  0x73, 0x73, 0x73, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xB5, 0xB5, 0xB5, 0xFF, 0xB8, 0x55, 0x00, 0xFF, 0xC3, 0x5F, 0x15, 0xFF, 0xCC, 0x6A, 0x1C, 0xFF,
  0xD4, 0x73, 0x22, 0xFF, 0xDE, 0x82, 0x35, 0xFF, 0xE3, 0x8C, 0x42, 0xFF, 0xEA, 0x96, 0x4D, 0xFF,
  0xEB, 0x9B, 0x55, 0xFF, 0xED, 0x9E, 0x59, 0xFF, 0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF,
  0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF,
  0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF,
  0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF,
  0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF,
  0xF2, 0xA6, 0x61, 0xFF, 0xF2, 0xA6, 0x61, 0xFF, 0xED, 0x9E, 0x59, 0xFF, 0xE5, 0x94, 0x4D, 0xFF,
  0xDF, 0x8A, 0x42, 0xFF, 0xD4, 0x7C, 0x33, 0xFF, 0xCE, 0x72, 0x22, 0xFF, 0xCC, 0x6A, 0x1C, 0xFF,
  0xC3, 0x5F, 0x15, 0xFF, 0xB4, 0x54, 0x00, 0xFF, 0x67, 0x67, 0x67, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF,
  0xDD, 0xDD, 0xDD, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0xA9, 0x62, 0x2B, 0xFF,
  0xCC, 0x6A, 0x1C, 0xFF, 0xD4, 0x73, 0x22, 0xFF, 0xDA, 0x7F, 0x35, 0xFF, 0xE4, 0x90, 0x46, 0xFF,
  0xF1, 0x9D, 0x54, 0xFF, 0xF8, 0xA7, 0x60, 0xFF, 0xFB, 0xAC, 0x66, 0xFF, 0xFE, 0xB2, 0x6D, 0xFF,
  0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF,
  0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF,
  0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF,
  0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF,
  0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF, 0xFE, 0xB5, 0x74, 0xFF,
  0xFA, 0xAF, 0x6E, 0xFF, 0xEE, 0xA2, 0x5D, 0xFF, 0xE9, 0x96, 0x50, 0xFF, 0xDF, 0x8A, 0x42, 0xFF,
  0xD4, 0x7C, 0x33, 0xFF, 0xCE, 0x72, 0x22, 0xFF, 0xC7, 0x69, 0x1C, 0xFF, 0xA0, 0x59, 0x22, 0xFF,
  0x69, 0x69, 0x69, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0x9C, 0x73, 0x50, 0xFF, 0xCE, 0x72, 0x22, 0xFF, 0xD4, 0x7C, 0x33, 0xFF,
  0xE1, 0x89, 0x3D, 0xFF, 0xF1, 0x9D, 0x54, 0xFF, 0xFB, 0xAC, 0x66, 0xFF, 0xFE, 0xB2, 0x6D, 0xFF,
  0xFF, 0xBC, 0x74, 0xFF, 0xFF, 0xC4, 0x7C, 0xFF, 0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF,
  0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF,
  0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF,
  0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF,
  0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF,
  0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xC4, 0x7C, 0xFF, 0xFE, 0xB2, 0x6D, 0xFF,
  0xF5, 0xA5, 0x5E, 0xFF, 0xEA, 0x96, 0x4D, 0xFF, 0xDA, 0x84, 0x3B, 0xFF, 0xD4, 0x7C, 0x33, 0xFF,
  0xCE, 0x72, 0x22, 0xFF, 0x83, 0x5A, 0x38, 0xFF, 0x82, 0x82, 0x82, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0x9B, 0x91, 0x88, 0xFF,
  0xA3, 0x6A, 0x3B, 0xFF, 0xD4, 0x80, 0x38, 0xFF, 0xE4, 0x90, 0x46, 0xFF, 0xFB, 0xA6, 0x5A, 0xFF,
  0xFF, 0xB8, 0x6E, 0xFF, 0xFF, 0xC4, 0x7C, 0xFF, 0xFF, 0xD0, 0x87, 0xFF, 0xFF, 0xCD, 0x8D, 0xFF,
  0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF,
  0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF,
  0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF,
  0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF,
  0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF,
  0xFF, 0xCD, 0x8D, 0xFF, 0xFF, 0xC4, 0x7C, 0xFF, 0xFE, 0xB2, 0x6D, 0xFF, 0xF1, 0xA0, 0x57, 0xFF,
  0xE3, 0x8C, 0x42, 0xFF, 0xD4, 0x80, 0x38, 0xFF, 0x9E, 0x63, 0x33, 0xFF, 0x66, 0x5C, 0x54, 0xFF,
  0xA5, 0xA5, 0xA5, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF,
  0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF,
  0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF,
  0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF,
  0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF, 0x8E, 0x7B, 0x6D, 0xFF, 0xA8, 0x6F, 0x40, 0xFF,
  0xE4, 0x90, 0x46, 0xFF, 0xF9, 0xA8, 0x5F, 0xFF, 0xFF, 0xBC, 0x74, 0xFF, 0xFF, 0xCC, 0x82, 0xFF,
  0xFF, 0xD5, 0x8C, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF,
  0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF,
  0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF,
  0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF,
  0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF,
  0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xE6, 0x9F, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xCC, 0x82, 0xFF,
  0xFF, 0xBC, 0x74, 0xFF, 0xF5, 0xA5, 0x5E, 0xFF, 0xE4, 0x90, 0x46, 0xFF, 0xA3, 0x6A, 0x3B, 0xFF,
  0x70, 0x5D, 0x4E, 0xFF, 0x7F, 0x7F, 0x7F, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF,
  0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF,
  0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF,
  0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF,
  0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF,
  0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF,
  0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF,
  0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF,
  0xF2, 0xF2, 0xF2, 0xFF, 0xF2, 0xF2, 0xF2, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF,
  0xAC, 0xAC, 0xAC, 0xFF, 0x85, 0x7C, 0x74, 0xFF, 0x8C, 0x6A, 0x4C, 0xFF, 0xB8, 0x80, 0x50, 0xFF,
  0xEC, 0xA3, 0x66, 0xFF, 0xFF, 0xBD, 0x7A, 0xFF, 0xFF, 0xC7, 0x84, 0xFF, 0xFF, 0xCD, 0x8D, 0xFF,
  0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF,
  0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF,
  0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF,
  0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF,
  0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF, 0xFF, 0xDE, 0x97, 0xFF,
  0xFF, 0xD5, 0x8C, 0xFF, 0xFF, 0xC4, 0x7C, 0xFF, 0xEC, 0xA3, 0x66, 0xFF, 0xB8, 0x80, 0x50, 0xFF,
  0x85, 0x63, 0x44, 0xFF, 0x6A, 0x60, 0x59, 0xFF, 0x7F, 0x7F, 0x7F, 0xFF, 0xC3, 0xC3, 0xC3, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xB5, 0xB5, 0xB5, 0xFF,
  0x91, 0x91, 0x91, 0xFF, 0x7F, 0x7F, 0x7F, 0xFF, 0x7F, 0x7F, 0x7F, 0xFF, 0x69, 0x69, 0x69, 0xFF,
  0x67, 0x67, 0x67, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF,
  0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF,
  0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF,
  0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF,
  0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF,
  0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF, 0x5C, 0x5C, 0x5C, 0xFF,
  0x67, 0x67, 0x67, 0xFF, 0x69, 0x69, 0x69, 0xFF, 0x73, 0x73, 0x73, 0xFF, 0x91, 0x91, 0x91, 0xFF,
  0xC3, 0xC3, 0xC3, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF,
  0xED, 0xED, 0xED, 0xFF, 0xED, 0xED, 0xED, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xDD, 0xDD, 0xDD, 0xFF, 0xCD, 0xCD, 0xCD, 0xFF, 0xBD, 0xBD, 0xBD, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xB5, 0xB5, 0xB5, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF,
  0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF,
  0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF,
  0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF,
  0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF,
  0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF,
  0xA5, 0xA5, 0xA5, 0xFF, 0xA5, 0xA5, 0xA5, 0xFF, 0xA5, 0xA5, 0xA5, 0xFF, 0xAC, 0xAC, 0xAC, 0xFF,
  0xBD, 0xBD, 0xBD, 0xFF, 0xD5, 0xD5, 0xD5, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
  0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF, 0xE4, 0xE4, 0xE4, 0xFF,
};

/*** sAQUA_BITMAP *************************************************************/
/* Purpose : g_anAQUA_BITMAP's image header for CBitmap::CreateBitmapIndirect */
/* Unit    : BITMAP                                                           */
/* Range   : structure list                                                   */
/* List    :  0 - int            bmType       : bitmap type (0)               */
/*            1 - int            bmWidth      : width  in pixels (>0)         */
/*            2 - int            bmHeight     : height in pixels (>0)         */
/*            3 - int            bmWidthBytes ; number of bytes per line (%2) */
/*            4 - unsigned char  bmPlanes     ; number of color planes        */
/*            5 - unsigned char  bmBitsPixel  : number of bits per pixel      */
/*            6 - unsigned char* bmBits       : pointer to an array of shorts */
/* Example : None                                                             */
/* WARNING : I said SHORT for <bmBits> because the number of bytes must be    */
/*           divible by 2 ! But in facts, it can be bytes, longs, whatever,   */
/*           as long as the size of the array remains divisible by 2...       */
/******************************************************************************/
BITMAP sAQUA_BITMAP =
{ 0               // bmType
, 90              // bmWidth
, 16              // bmHeight
, 360             // bmWidthBytes
, 1               // bmPlanes
, 32              // bmBitsPixel
, g_anAQUA_BITMAP // bmBits
};
#endif // dCSP_RESOURCE_BITMAP

/*** g_anThreeDots ************************************************************/
/* Purpose : dots for reduced string                                          */
/* Unit    : char                                                             */
/* Range   : [0-127] - LIMITED selection                                      */
/* List    : None                                                             */
/* Example : None                                                             */
/******************************************************************************/
const char g_anThreeDots[] = "...";

// *** CONSTRUCTORS ***

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : CSkinProgress                                              */
/* Role          : Default constructor  for status bar usage                  */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : Sets the default values to                                 */
/*                   i_poStrMessage = "Work in progress..."                   */
/*                   i_nUpper       = 100          - from 0 to 100            */
/*                   i_nProgress    = cSPT_PERCENT - DISPLAY PERCENT          */
/*                   i_nPane        = 0            - Share the text pane      */
/*                   i_nSize        = 200          - 200 pixels FORCED WIDTH  */
/*                   i_poBitmap     = NULL         - USE EMBEDDED BITMAP      */
/*                <> i_bReverse     = FALSE        - normal display           */
/* Behavior      : A - Create the progress bar using default parameters       */
/*----------------------------------------------------------------------------*/
/* PROC CSkinProgress                                                         */
/*                                                                            */
/* A..... Create a status progress bar with "Work in progress..." as text     */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
CSkinProgress::CSkinProgress
(
)
{ // Default constructor

  // Init

  // Process

// A..... Create a default progress bar in Status Bar with "Work in progress..." as text
  _ProgressInStatusBar("Work in progress");
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : CSkinProgress                                              */
/* Role          : Default constructor with parameters for status bar usage   */
/* Type          : public                                                     */
/* Interface     : RETURN (pointer to value, direct value)                    */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_poStrMessage : The text message to display in pane 0   */
/*                   i_nUpper       : Upper limit to reach 100% (0 at 0%)     */
/*                   i_nProgress    : Progress completion message type        */
/*                   i_nPane        : Pane number for the progress bar        */
/*                   i_nSize        : Progress bar width in pixel IF pane 0   */
/*                   i_poBitmap     : Replacement progress bar bitmap         */
/*                <> i_bReverse     : Reverse display of the progress bar     */
/* Pre-condition : None                                                       */
/* Constraints   : At least, <i_poStrMessage> must be provided                */
/* Behavior      : A - Create the progress bar using user's parameters        */
/*----------------------------------------------------------------------------*/
/* PROC CSkinProgress                                                         */
/*                                                                            */
/* A..... Create the progress bar using user's parameters                     */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
CSkinProgress::CSkinProgress
( LPCTSTR  i_poStrMessage // Text to display
, int      i_nUpper       // = 100          : Default range from 0 to i_nUpper
, int      i_nProgress    // = cSPT_PERCENT : Message type to add to the text
, int      i_nPane        // = 0            : Pane number in which display the progress bar
, int      i_nSize        // = 200          : Size of the progress bar if in pane 0
, CBitmap* i_poBitmap     // = NULL         : Pointer to a user bitmap
#ifdef dCSP_SLIDERBAR_METHOD
, BOOL     i_bReverse     // = FALSE        : Reverse display of the progress bar
#endif // dCSP_SLIDERBAR_METHOD
)
{ // Default constructor with parameters for status bar usage

  // Init

  // Process

// A..... Create the progress bar using user's parameters
  _ProgressInStatusBar
  ( i_poStrMessage
  , i_nUpper
  , i_nProgress
  , i_nPane
  , i_nSize
  , i_poBitmap
#ifdef dCSP_SLIDERBAR_METHOD
  , i_bReverse
#endif // dCSP_SLIDERBAR_METHOD
  );
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : CSkinProgress                                              */
/* Role          : Default constructor with parameters for dialog usage       */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_poWndProgress : The CWnd where to display the progress */
/*                   i_nUpper        : Upper limit to reach 100% (0 at 0%)    */
/*                   i_poBitmap      : Replacement progress bar bitmap        */
/*                <> i_bReverse      : Reverse display of the progress bar    */
/*                   i_poWndMessage  : The CWnd where to display the text     */
/*                   i_poStrMessage  : The text message to display            */
/*                   i_nProgress     : Progress completion message type       */
/* Pre-condition : None                                                       */
/* Constraints   : At least, <i_poStrMessage> must be provided                */
/* Behavior      : A - Create the dialog progress bar using user's parameters */
/*----------------------------------------------------------------------------*/
/* PROC CSkinProgress                                                         */
/*                                                                            */
/* A..... Create the dialog progress bar using user's parameters              */
/*----------------------------------------------------------------------------*/
/* The most simple dialog CSkinProgress constructor :                         */
/*   CSkinProgress oCspBar(&oCStatic); // Use 100 as upper limit              */
/*--- END FUNCTION HEADER ----------------------------------------------------*/
#ifdef dCSP_DIALOG_PROGRESS
CSkinProgress::CSkinProgress
( CWnd*    i_poWndProgress // Pointer to the anchor CWnd to use for the progress bar
, int      i_nUpper        // = 100,      : Default range from 0 to i_nUpper
, CBitmap* i_poBitmap      // = NULL      : Pointer to a user bitmap
#ifdef dCSP_SLIDERBAR_METHOD
, BOOL     i_bReverse      // = FALSE,    : Reverse display of the progress bar
#endif // dCSP_SLIDERBAR_METHOD
, CWnd*    i_poWndMessage  // = NULL,     : Pointer to the anchor CWnd to use for the text pane
, LPCTSTR  i_poStrMessage  // = NULL      : Text to display,
, int      i_nProgress     // = cSPT_NONE : Message type to add to the text
)
{ // Default constructor with parameters for dialog usage

  // Init

  // Process

// A..... Create the progress bar using user's parameters
  _ProgressInDialog
  ( i_poWndProgress
  , i_nUpper
  , i_poBitmap
#ifdef dCSP_SLIDERBAR_METHOD
  , i_bReverse
#endif // dCSP_SLIDERBAR_METHOD
  , i_poWndMessage
  , i_poStrMessage
  , i_nProgress
  );
}
#endif // dCSP_DIALOG_PROGRESS

// *** INITIALIZATORS ***

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : _CreateCommon                                              */
/* Role          : Initialize the progress with its basic parameters          */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : Error during progress bar creation        */
/*                          TRUE  : Progress bar created                      */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_poStrMessage  : The text message to display in pane 0  */
/*                   i_nUpper        : Upper limit to reach 100% (0 at 0%)    */
/*                   i_nProgress     : Progress completion message type       */
/*                   i_poBitmap      : Replacement progress bar bitmap        */
/*                <> i_bReverse      : Reverse display of the progress bar    */
/* Pre-condition : None                                                       */
/* Constraints   : Base of progress bar is fixed to 0, must use               */
/*                 [SetRange(...)] to change it...                            */
/* Behavior      : A - Set base values                                        */
/*                 B - Set the bitmap                                         */
/*                 C - Set the progress bar values                            */
/*                 D - Get the creation date and time of the progress bar     */
/*                 E - Set the refresh timer                                  */
/*                 F - Resize the text and display the whole things           */
/*----------------------------------------------------------------------------*/
/* PROC _CreateCommon                                                         */
/*                                                                            */
/* A..... Set base values                                                     */
/* B..... Set the bitmap                                                      */
/* C..... Set the progress bar values                                         */
/* D..... Get the creation date and time of the progress bar                  */
/* E..... Set the refresh timer to 500 milliseconds                           */
/* F..... Resize the text and display the whole things                        */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CSkinProgress::_CreateCommon
( LPCTSTR  i_poStrMessage
, int      i_nUpper       // = 100
, int      i_nProgress    // = cSPT_PERCENT
, CBitmap* i_poBitmap     // = NULL
#ifdef dCSP_SLIDERBAR_METHOD
, BOOL     i_bReverse     // = FALSE
#endif // dCSP_SLIDERBAR_METHOD
)
{
  // Init

// A..... Set base values
  mp_poBaseBmp       = NULL;
  mp_poCompatibleBmp = NULL;
  mp_poStretchBmp    = NULL;
  mp_poProgressBmp   = NULL;
  mp_oStrPrevMessage = "";
  mp_oRectPane.SetRect(0, 0, 0, 0);

// Process + Return

// B..... Set the bitmap
  if
  (
    SetBitmap
    ( i_poBitmap
#ifndef dCSP_TIMED_REDRAW
    , FALSE
#endif // dCSP_TIMED_REDRAW
    )
    == FALSE
  )
  {
    return FALSE;
  }
  else
  {
// C..... Set the progress bar values
    // Set the progress text type
    mp_nProgressText = i_nProgress;

    // Set range and step
    mp_nLower = 0; // Set first parameters for the resampling

    ASSERT(i_nUpper > 0); // mp_nLower is 0, mp_nUpper CANNOT BE BEFORE mp_nLower quite now
    mp_nUpper = i_nUpper;

#ifdef dCSP_SLIDERBAR_METHOD
    mp_nLeft  = 0;
#endif // dCSP_SLIDERBAR_METHOD

    mp_nRight = 0;

    SetRange
    ( 0
    , i_nUpper
    , 1
    , FALSE
#ifndef dCSP_TIMED_REDRAW
    , FALSE // Don't resample range, and avoid display there !
#endif // dCSP_TIMED_REDRAW
    );

    // Set and save additional values
    mp_oStrMessage = i_poStrMessage;
#ifdef dCSP_SLIDERBAR_METHOD
    mp_bReverse    = i_bReverse;
#endif // dCSP_SLIDERBAR_METHOD

// D..... Get the creation date and time of the progress bar and set its position to the beginning
    Reset
    (
#ifndef dCSP_TIMED_REDRAW
      FALSE
#endif // dCSP_TIMED_REDRAW
    );

// E..... Set the refresh timer to 500 milliseconds (or 20ms/50Hz in <dCSP_TIMED_REDRAW> mode)
    SetTimer
    ( (UINT) this // Use object's unique address as timer identifier
#ifndef dCSP_TIMED_REDRAW
    , 500
#else
    , 20
#endif // dCSP_TIMED_REDRAW
    , NULL
    );

// F..... Resize the text and display the whole things
    RefreshPanes(); // Set the text in pane 0 and do the first drawing of the SkinProgress bar

    return TRUE;
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : _ProgressInStatusBar                                       */
/* Role          : Create the progress in status bar with basic parameters    */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : Error during progress bar creation        */
/*                          TRUE  : Progress bar created                      */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_poStrMessage  : The text message to display in pane 0  */
/*                   i_nUpper        : Upper limit to reach 100% (0 at 0%)    */
/*                   i_nProgress     : Progress completion message type       */
/*                   i_nPane         : Pane number for the progress bar       */
/*                   i_nSize         : Progress bar width in pixel IF pane 0  */
/*                   i_poBitmap      : Replacement progress bar bitmap        */
/*                <> i_bReverse      : Reverse display of the progress bar    */
/* Pre-condition : None                                                       */
/* Constraints   : Base of progress bar is fixed to 0, must use [SetRange] to */
/*                 change it...                                               */
/* Behavior      : A - Get status bar handler                                 */
/*                 B - Create a CStatic object upon the target pane           */
/*                 C - Specific Status Bar initialization                     */
/*                 D - Create and initialize the progress bar                 */
/*----------------------------------------------------------------------------*/
/* PROC _ProgressInStatusBar                                                  */
/*                                                                            */
/* A..... Get status bar handler                                              */
/* [IF there is a status bar]                                                 */
/* : B..... Create a CStatic object upon the target status bar pane           */
/* : [IF CStatic creation OK]                                                 */
/* : : C..... Specific Status Bar initialization                              */
/* : : D..... Create and initialize the progress bar                          */
/* : [ENDIF]                                                                  */
/* [ENDIF]                                                                    */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CSkinProgress::_ProgressInStatusBar
( LPCTSTR  i_poStrMessage // Text to display
, int      i_nUpper       // = 100,         : Default range from 0 to i_nUpper
, int      i_nProgress    // = cSPT_PERCENT : Message type to add to the text
, int      i_nPane        // = 0,           : Pane number in which display the progress bar
, int      i_nSize        // = 200,         : Size of the progress bar if in pane 0
, CBitmap* i_poBitmap     // = NULL         : Pointer to a user bitmap
#ifdef dCSP_SLIDERBAR_METHOD
, BOOL     i_bReverse     // = FALSE
#endif // dCSP_SLIDERBAR_METHOD
)
{ // The initialization routine
  BOOL        l_bSuccess;
  CStatusBar* l_poStatusBar;
  DWORD       l_nStyleEx;
  DWORD       l_nStyle;
  CRect       l_oRectPane;

  LPCSTR      l_poStrClass;
  UINT        l_nClassStyle;

  // Init

  l_bSuccess = FALSE;

#ifdef dCSP_DIALOG_PROGRESS
  mp_poWndProgress = NULL;
  mp_poWndMessage  = NULL;
#endif // dCSP_DIALOG_PROGRESS

  // Process

// A..... Get status bar handler
  l_poStatusBar = _GetStatusBar();
  if(l_poStatusBar != NULL)
  {
// B..... Create a CStatic object upon the target status bar pane
    // Set the style for the custom progress bas
    l_nClassStyle = 0; // CS_CLASSDC | CS_HREDRAW | CS_VREDRAW;
    l_nStyleEx    = WS_EX_STATICEDGE;
    l_nStyle      = WS_CHILD | WS_VISIBLE | SS_BITMAP | SS_CENTERIMAGE;

    // Get CRect coordinates for requested status bar pane
    l_poStatusBar->GetItemRect
    ( i_nPane
    , &l_oRectPane
    );

    // Create the progress bar
    l_poStrClass
    = AfxRegisterWndClass
      ( l_nClassStyle
      , AfxGetApp()->LoadStandardCursor(IDC_WAIT)
      )
    ;
    
    l_bSuccess
    = CStatic::CreateEx
      ( l_nStyleEx
      , l_poStrClass
      , ""
      , l_nStyle
      , l_oRectPane
      , l_poStatusBar
      , (UINT) this // Use object's unique address as child window identifier
      )
    ;

    ASSERT(l_bSuccess == TRUE);
    if(l_bSuccess == FALSE)
    {
      return FALSE;
    }
    else
    {
#ifdef dCSP_VERTICAL_BAR
#ifndef dCSP_DISPLAY_STRETCH
      mp_bVertical = FALSE; // *ALWAYS FALSE IN CSkinProgress while in StatusBar mode*
#else
      mp_bVertical = TRUE;  // *FORCE* vertical for mp_poStretchBmp analysis
#endif // dCSP_DISPLAY_STRETCH
#endif // dCSP_VERTICAL_BAR

// C..... Specific Status Bar initialization
      SetSize
      ( i_nSize
#ifndef dCSP_TIMED_REDRAW
      , FALSE // Set the size, and avoid display there !
#endif // dCSP_TIMED_REDRAW
      );

      mp_nPane        = i_nPane;
      mp_oStrPrevText = l_poStatusBar->GetPaneText(mp_nPane); // Get the previous pane's text
     
// D..... Create and initialize the progress bar
      l_bSuccess
      = _CreateCommon
        ( i_poStrMessage
        , i_nUpper
        , i_nProgress
        , i_poBitmap
#ifdef dCSP_SLIDERBAR_METHOD
        , i_bReverse
#endif // dCSP_SLIDERBAR_METHOD
        )
      ;

      return l_bSuccess;
    }
  }
  else
  {
    return FALSE;
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : _ProgressInDialog                                          */
/* Role          : Create the progress bar in a dialog with basic parameters  */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : Error during progress bar creation        */
/*                          TRUE  : Progress bar created                      */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_poWndProgress : The CWnd where to display the progress */
/*                   i_nUpper        : Upper limit to reach 100% (0 at 0%)    */
/*                   i_poBitmap      : Replacement progress bar bitmap        */
/*                <> i_bReverse      : Reverse display of the progress bar    */
/*                   i_poWndMessage  : The CWnd where to display the text     */
/*                   i_poStrMessage  : The text message to display in pane 0  */
/*                   i_nProgress     : Progress completion message type       */
/* Pre-condition : None                                                       */
/* Constraints   : Base of progress bar is fixed to 0, must use [SetRange] to */
/*                 change it...                                               */
/* Behavior      : A - Get status bar handler                                 */
/*                 B - Create a CStatic object upon the target pane           */
/*                 C - Set the <mp_bVertical> flag                            */
/*                 D - Specific Status Bar initialization                     */
/*                 E - Create and initialize the progress bar                 */
/*----------------------------------------------------------------------------*/
/* PROC _ProgressInDialog                                                     */
/*                                                                            */
/* A..... Specific Dialog initialization                                      */
/* B..... Create a CStatic object upon the target CWnd progress bar pane      */
/* [IF CStatic creation OK]                                                   */
/* : C..... Set the <mp_bVertical> flag if the progress bar pane is vertical  */
/* : [IF there is a CWnd anchor for a text pane to create]                    */
/* : : D..... Specific Status Bar initialization                              */
/* : [ENDIF]                                                                  */
/* : E..... Create and initialize the progress bar                            */
/* [ENDIF]                                                                    */
/*----------------------------------------------------------------------------*/
/* Well, sorry, I put <i_bReverse> in the middle of the function call, but    */
/* there is an obvious reason : If you want to bypass the message's Cwnd,     */
/* you can leave the ending parameters empty ! But if I had put <i_bReverse>  */
/* on the end, you had to force every text related parameter to NULL before   */
/* being able to set the <i_bReverse> value.                                  */
/*                                                                            */
/* You can also use yourself the <dCSP_SLIDERBAR_METHOD> define to compile    */
/* your own code according to your needs (as long as you include the .h) !    */
/*--- END FUNCTION HEADER ----------------------------------------------------*/
#ifdef dCSP_DIALOG_PROGRESS
BOOL CSkinProgress::_ProgressInDialog
( CWnd*    i_poWndProgress
, int      i_nUpper        // = 100,      : Default range from 0 to i_nUpper
, CBitmap* i_poBitmap      // = NULL      : Pointer to a user bitmap
#ifdef dCSP_SLIDERBAR_METHOD
, BOOL     i_bReverse      // = FALSE
#endif // dCSP_SLIDERBAR_METHOD
, CWnd*    i_poWndMessage  // = NULL
, LPCTSTR  i_poStrMessage  // = NULL      : Text to display
, int      i_nProgress     // = cSPT_NONE : Message type to add to the text
)
{ // The initialization routine
  BOOL     l_bSuccess;
  DWORD    l_nStyleEx;
  DWORD    l_nStyle;
  CRect    l_oRectPane;

  LPCSTR   l_poStrClass;
  UINT     l_nClassStyle;

  // Init

  l_bSuccess = FALSE;

// A..... Specific Dialog initialization
  mp_poWndProgress = i_poWndProgress;
  mp_poWndMessage  = i_poWndMessage;

  // Process + Return

// B..... Create a CStatic object upon the target CWnd progress bar pane
  // Set the style for the custom progress bas
  l_nClassStyle = 0; // CS_CLASSDC | CS_HREDRAW | CS_VREDRAW;
  l_nStyleEx    = WS_EX_STATICEDGE;
  l_nStyle      = WS_CHILD | WS_VISIBLE | SS_BITMAP | SS_CENTERIMAGE;

  // Get CRect coordinates for requested target CWnd bar pane
  _GetTargetRect(&l_oRectPane);

  // Create the progress bar
  l_poStrClass
  = AfxRegisterWndClass
    ( l_nClassStyle
    , AfxGetApp()->LoadStandardCursor(IDC_WAIT)
    )
  ;
  
  l_bSuccess
  = CStatic::CreateEx
    ( l_nStyleEx
    , l_poStrClass
    , ""
    , l_nStyle
    , l_oRectPane
    , mp_poWndProgress->GetParent() // Attach it not the the CWnd anchor (thus getting in its client area) but to its parent to overlap it
    , (UINT) this // Use object's unique address as child window identifier
    )
  ;

  ASSERT(l_bSuccess == TRUE);
  if(l_bSuccess == FALSE)
  {
    return FALSE;
  }
  else
  {
// C..... Set the <mp_bVertical> flag if the progress bar pane is vertical
#ifdef dCSP_VERTICAL_BAR
#ifndef dCSP_DISPLAY_STRETCH
    if
    (
        l_oRectPane.Height()
      > l_oRectPane.Width()
    )
    { // VERTICAL
      mp_bVertical = TRUE;
    }
    else
    {
      mp_bVertical = FALSE;
    }
#else
    mp_bVertical = TRUE;  // *FORCE* vertical for <mp_poStretchBmp> analysis
#endif // dCSP_DISPLAY_STRETCH
#endif // dCSP_VERTICAL_BAR

    if(mp_poWndMessage != NULL)
    {
// D..... Specific Status Bar initialization
      mp_poWndMessage->GetWindowText(mp_oStrPrevText); // Get the previous pane's text
    }else{}

    if(l_bSuccess == TRUE)
    {
// E..... Create and initialize the progress bar
      l_bSuccess
      = _CreateCommon
        ( i_poStrMessage
        , i_nUpper
        , i_nProgress
        , i_poBitmap
#ifdef dCSP_SLIDERBAR_METHOD
        , i_bReverse
#endif // dCSP_SLIDERBAR_METHOD
        )
      ;
    }else{}

    return l_bSuccess;
  }
}
#endif // dCSP_DIALOG_PROGRESS

// *** DESCTRUCTOR ***

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : ~CSkinProgress                                             */
/* Role          : Destructor, restore the inital states and used memory      */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - _Clear the progress bar                                */
/*                 B - Delete the refresh timer                               */
/*                 C - Delete the base bitmap                                 */
/*                 C - Delete the client DC compatible base bitmap            */
/*                 D - Delete the stretched for image list bitmap             */
/*                 E - Delete the displayed progress bar bitmap               */
/*----------------------------------------------------------------------------*/
/* PROC ~CSkinProgress                                                        */
/*                                                                            */
/* A..... _Clear the progress bar                                             */
/* B..... Delete the refresh timer                                            */
/* C..... Delete the <mp_poBaseBmp> base bitmap                               */
/* D..... Delete the <mp_poCompatibleBmp> client DC compatible base bitmap    */
/* E..... Delete the <mp_poStretchBmp> stretched for image list bitmap        */
/* F..... Delete the <mp_poProgressBmp> displayed progress bar bitmap         */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
CSkinProgress::~CSkinProgress
(
)
{ // Destructor

  // Init

  // Process

// A..... _Clear the progress bar
  _Clear();

// B..... Delete the refresh timer
  if(IsWindow(this->m_hWnd)) // Test first if <this> is the correct address of the object before using it as the right timer identifier
  {
    KillTimer((UINT) this); // Use object's unique address as timer identifier
  }else{}

// C..... Delete the <mp_poBaseBmp> base bitmap
  if(mp_poBaseBmp != NULL)
  { // Delete the attached base bitmap
    delete mp_poBaseBmp;
  }else{}

// D..... Delete the <mp_poCompatibleBmp> client DC compatible base bitmap
  if(mp_poCompatibleBmp != NULL)
  { // Delete the attached client DC compatible base bitmap
    delete mp_poCompatibleBmp;
  }else{}

// E..... Delete the <mp_poStretchBmp> stretched for image list bitmap
  if(mp_poStretchBmp != NULL)
  { // Delete the attached stretched image list bitmap
    delete mp_poStretchBmp;
  }else{}

// F..... Delete the <mp_poProgressBmp> displayed progress bar bitmap
  if(mp_poProgressBmp != NULL)
  { // Delete the attached progress bitmap
    delete mp_poProgressBmp;
  }else{}
}

// *** CLEANER ***

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : _Clear                                                     */
/* Role          : Erase the progress                                         */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Delete the progress bar                                */
/*                 B - Set IDLE message in pane 0                             */
/*                 C - Set previous message in user pane                      */
/*                 D - Display the changes                                    */
/*                 E - Set previous message                                   */
/*----------------------------------------------------------------------------*/
/* PROC _Clear                                                                */
/*                                                                            */
/* [IF the object is still alive]                                             */
/* : A..... Delete the progress bar                                           */
/* : [IF status bar]                                                          */
/* : : B..... Set IDLE message in pane 0                                      */
/* : : C..... Set previous message in user pane                               */
/* : : D..... Display the changes                                             */
/* : [ELSE]                                                                   */
/* : : [IF there is a text CWnd]                                              */
/* : : : E..... Set previous message                                          */
/* : : [ENDIF]                                                                */
/* : [ENDIF]                                                                  */
/* [ENDIF]                                                                    */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
void CSkinProgress::_Clear
(
)
{ // Deletion of the progress bar, restoration of the context
  CStatusBar* l_poStatusBar;

  //

  if(IsWindow(GetSafeHwnd()))
  {
// A..... Delete the progress bar
    ModifyStyle(WS_VISIBLE, 0); // _Clear the attached CStatic progress bar
    DestroyWindow(); // Destroy it

#ifdef dCSP_DIALOG_PROGRESS
    if(mp_poWndProgress == NULL)
    { // If in Status Bar, reset pane 0 and delete the progress bar
#endif // dCSP_DIALOG_PROGRESS
      l_poStatusBar = _GetStatusBar();
      if(l_poStatusBar != NULL)
      {
// B..... Set IDLE message in pane 0
        mp_oStrMessage.LoadString(AFX_IDS_IDLEMESSAGE); // Get the IDLE_MESSAGE and place ît in the status bar 
        l_poStatusBar->SetPaneText(0, mp_oStrMessage);

// C..... Set previous message in user pane
        if(mp_nPane != 0)
        { // If not the text pane, restore previous text in the pane
          l_poStatusBar->SetPaneText(mp_nPane, mp_oStrPrevText);
        }else{}

// D..... Display the changes
        l_poStatusBar->InvalidateRect(NULL);
      }else{}
#ifdef dCSP_DIALOG_PROGRESS
    }
    else
    {
      if(mp_poWndMessage != NULL)
      {
// E..... Set previous message
        mp_poWndMessage->SetWindowText(mp_oStrPrevText); // Set the previous pane's text
      }else{}

      mp_poWndProgress->InvalidateRect(NULL);
    } // NOTHING TO RESET IN DIALOG MODE !!!
#endif // dCSP_DIALOG_PROGRESS
  }else{}
}

// *** SYSTEM INTERFACE ***

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : _GetStatusBar                                              */
/* Role          : Get status bar's window handle                             */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   CStatusBar* : Window handle, else NULL if no status bar  */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Get the main window handle                             */
/*                 B - Retrieve the status bar handle                         */
/*----------------------------------------------------------------------------*/
/* PROC _GetStatusBar                                                         */
/*                                                                            */
/* A..... Get the main window handle                                          */
/* B..... Retrieve the status bar handle                                      */
/* [IF main window is based on CFrameWnd]                                     */
/* : BA.... Return status bar's handle from CFrameWnd main window type        */
/* :[ELSE]                                                                    */
/* : BB.... Return status bar's handle from other main window type            */
/* [ENDIF]                                                                    */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
CStatusBar* CSkinProgress::_GetStatusBar
(
)
{ // Get the pointer on the current status bar
  CWnd* l_poMainWnd;
  CWnd* l_poMessageBar;

  // Init

// A..... Get the main window handle
  l_poMainWnd = AfxGetMainWnd();

  // Process + Return

// B..... Retrieve the status bar handle
  if(l_poMainWnd != NULL)
  {
    if(l_poMainWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd)))
    { // If main window is a frame window, use normal methods
      l_poMessageBar = ((CFrameWnd*) l_poMainWnd)->GetMessageBar();
      
// BA.... Return status bar's handle from CFrameWnd main window type
      return DYNAMIC_DOWNCAST(CStatusBar, l_poMessageBar);
    }
    else
    { // otherwise traverse children to try and find the status bar
// BB.... Return status bar's handle from other main window type
      return DYNAMIC_DOWNCAST(CStatusBar, l_poMainWnd->GetDescendantWindow(AFX_IDW_STATUS_BAR));
    }
  }
  else
  {
    return NULL;
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : _GetTargetRect                                             */
/* Role          : Get the target CRect of the progress bar                   */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : Error in getting the target rect          */
/*                          TRUE  : CRect returned is valid                   */
/*                 OUTPUT (pointer to value)                                  */
/*                   o_poProgressRect : Pointer on an existing CRect          */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Get the progress bar's CWnd anchor rectangle           */
/*                 B - Get the status bar selected pane rectangle             */
/*----------------------------------------------------------------------------*/
/* PROC _GetTargetRect                                                        */
/*                                                                            */
/* [IF there is a progress bar CWnd anchor specified]                         */
/* : A..... Get the progress bar's CWnd anchor rectangle                      */
/* [ELSE]                                                                     */
/* : B..... Get the status bar selected pane rectangle                        */
/* [ENDIF]                                                                    */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CSkinProgress::_GetTargetRect
( CRect* o_poProgressRect // Pointer on an existing CRect
)
{ // Get the target CRect for the [SetBitmap(...)]
  CStatusBar* l_poStatusBar;

  // Init

  // Process + Return

#ifdef dCSP_DIALOG_PROGRESS
  if(mp_poWndProgress != NULL)
  { // If dialog mode
// A..... Get the progress bar's CWnd anchor rectangle
    mp_poWndProgress->GetWindowRect(o_poProgressRect); // Return CWnd parent's screen absolute coordinates 
    mp_poWndProgress->GetParent()->ScreenToClient(o_poProgressRect); // Transform into parent relative coordinates

    return TRUE;
  }
  else
  {
#endif // dCSP_DIALOG_PROGRESS
    l_poStatusBar = _GetStatusBar();
    if(l_poStatusBar != NULL)
    {
// B..... Get the status sar selected pane rectangle
      l_poStatusBar->GetItemRect(mp_nPane, o_poProgressRect); // Already working in parent (the status bar) relative coordinates

      return TRUE;
    }
    else
    {
      return FALSE;
    }
#ifdef dCSP_DIALOG_PROGRESS
  }
#endif // dCSP_DIALOG_PROGRESS
}

// *** BITMAP PROCESS ***

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : SetBitmap                                                  */
/* Role          : Create an image list for the progress bar painting         */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : Error in image list creation              */
/*                          TRUE  : Image list created and ready to use       */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_poCwnd   : CWnd anchor to get the bitmap size to use   */
/*                   i_poBitmap : Image to use, use default bitmap if NULL    */
/*                   i_bDisplay : Display the changes                         */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Get the base bitmap for the image list creation        */
/*                 B - Create the stretched bitmap used for the image list    */
/*                 C - Create an image list compatible bitmap                 */
/*                 D - Create the image list                                  */
/*                 E - Display the new bitmap                                 */
/*----------------------------------------------------------------------------*/
/* PROC SetBitmap                                                             */
/*                                                                            */
/* A..... Get the base bitmap for the <mp_oBarImgLst> image list creation     */
/*   AA.... Create the base and the device compatible bitmaps                 */
/*   AB.... Load the <i_poBitmap> base bitmap                                 */
/*   AC.... Convert the <mp_poBaseBmp> base bitmap in a compatible format     */
/* B..... Create the stretched bitmap used for the image list creation        */
/*   BA.... Create the bitmap, and delete the previous one if there was one   */
/*   BB.... Create a bitmap with mixed dimensions from the base and the pane  */
/*   BC.... Set the copy parameters for the stretching                        */
/* C..... Modify the base bitmap to create an image list compatible bitmap    */
/* D..... Create the <mp_oBarImgLst> image list                               */
/*   DA.... Get the stretched bitmap size                                     */
/*   DB.... Calculate the size of every element of the image list             */
/*   DC.... Delete the previous image list the create a new one from scratch  */
/*   DD.... Create the new image list in 32 bits for maximun throughput       */
/*   DE.... Add the stretched bitmap in the image list                        */
/* E..... Display the new bitmap                                              */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CSkinProgress::SetBitmap
( CBitmap* i_poBitmap  // = NULL : Pointer to an existing bitmap
#ifndef dCSP_TIMED_REDRAW
, BOOL     i_bDisplay  // = TRUE : Display the changes
#endif // dCSP_TIMED_REDRAW
)
{ // Change of progress bar image
  BITMAP    l_sBmpSrc;
  CBitmap*  l_poOldBitmap;
  CBitmap*  l_poOldStretch;
  CRect     l_oRectBar;
  CDC       l_oDcBitmap;
  CDC       l_oDcStretch;

#ifdef dCSP_VERTICAL_BAR
  CBitmap   l_oBmpVertical;
  CBitmap*  l_poOldVertical;
  CDC       l_oDcVertical;
#endif // dCSP_VERTICAL_BAR

  // Init

  // Force redraw if the bitmap is changed while the SkinProgress object exist
  mp_oRectPaint.SetRect
  ( 0
  , 0
  , 0
  , 0
  );

#ifdef dCSP_VERTICAL_BAR
  l_poOldVertical = NULL; // AVOID /W4 -> BC.... *STUPID COMPILER*
#endif // dCSP_VERTICAL_BAR

  // Process

  if(_GetTargetRect(&l_oRectBar))
  { // If the target rectangle is valid
    CClientDC l_oDC(this); // Get the current DC

// A..... Get the <i_poBitmap> base bitmap for the <mp_oBarImgLst> image list creation
// AA.... Create the base and the device compatible bitmaps
    if(mp_poBaseBmp != NULL)
    { // *IF* mp_poBaseBmp already exist
      delete mp_poBaseBmp;
    }else{}

    mp_poBaseBmp = new CBitmap; // BEWARE : DON'T INITIALIZE IT YET !

    if(mp_poCompatibleBmp != NULL)
    { // *IF* mp_poCompatibleBmp already exist
      delete mp_poCompatibleBmp;
    }else{}

    mp_poCompatibleBmp = new CBitmap; // BEWARE : DON'T INITIALIZE IT YET !

// AB.... Load the <i_poBitmap> base bitmap
    // Check if i_poBitmap is valid, otherwise use the resource's bitmap
    if(i_poBitmap == NULL)
    { // If no bitmap provided, takes the default bitmap
#ifndef dCSP_RESOURCE_BITMAP
      mp_poBaseBmp->CreateBitmapIndirect(&sAQUA_BITMAP);
#else
      mp_poBaseBmp->LoadBitmap(IDB_AQUABAR); // Defaut bitmap, might have to be changed !
#endif // dCSP_RESOURCE_BITMAP
    }
    else
    { // Copy the <i_poBitmap> input bitmap as the new <mp_poBaseBmp> base bitmap
      CopyBitmap(mp_poBaseBmp, i_poBitmap);
    }

// AC.... Convert the <mp_poBaseBmp> base bitmap in a device compatible format
    ConvBitmap(mp_poCompatibleBmp, mp_poBaseBmp, &l_oDC);

    // Get bitmap width and height for the image list creation
    mp_poCompatibleBmp->GetBitmap(&l_sBmpSrc);

    mp_nBmpWidth  = l_sBmpSrc.bmWidth / cSPB_EnumElements; // cSPB_EnumElements == 9, the bitmap is actually composed of 9 parts
    mp_nBmpHeight = l_sBmpSrc.bmHeight;

// B..... Create the <mp_poStretchBmp> stretched bitmap used for the <mp_oBarImgLst> image list creation
// BA.... Create the bitmap, and if a previous one was already existing, delete it first
    if(mp_poStretchBmp != NULL)
    { // *IF* mp_poStretchBmp already exist
      delete mp_poStretchBmp;
    }else{}

    mp_poStretchBmp = new CBitmap;

// BB.... Create a bitmap with the base bitmap width, and the despination pane height minus 2
#ifdef dCSP_VERTICAL_BAR
    if(mp_bVertical == TRUE)
    { // Vertical bar
      l_oBmpVertical.CreateCompatibleBitmap
      ( &l_oDC
      , l_sBmpSrc.bmWidth
#ifndef dCSP_DISPLAY_STRETCH
      , l_oRectBar.Width()  - 2 // Minus 2, with don't count the contour of the box
#else
      , l_oRectBar.Height() - 2 // Minus 2, with don't count the contour of the box
#endif //dCSP_DISPLAY_STRETCH
      );

      mp_poStretchBmp->CreateCompatibleBitmap
      ( &l_oDC
#ifndef dCSP_DISPLAY_STRETCH
      , (l_oRectBar.Width()  - 2) * cSPB_EnumElements // Minus 2, with don't count the contour of the box
#else
      , (l_oRectBar.Height() - 2) * cSPB_EnumElements // Minus 2, with don't count the contour of the box
#endif //dCSP_DISPLAY_STRETCH
      , mp_nBmpWidth
      );
    }
    else
#endif // dCSP_VERTICAL_BAR
    { // Horizontal bar
      mp_poStretchBmp->CreateCompatibleBitmap
      ( &l_oDC // BITMAP CREATION IN CURRENT VIDEO MODE !
      , l_sBmpSrc.bmWidth
#ifndef dCSP_CREATE_BITMAP_FILE
      , l_oRectBar.Height() - 2 // Minus 2, with don't count the contour of the box
#else
      , l_sBmpSrc.bmHeight
#endif //dCSP_CREATE_BITMAP_FILE
      );
    }
   
// BC.... Set the copy parameters for the stretching
    // Set the DC
    l_oDcBitmap.CreateCompatibleDC(&l_oDC);
	  l_poOldBitmap  = l_oDcBitmap.SelectObject(mp_poCompatibleBmp); // Source

    l_oDcStretch.CreateCompatibleDC(&l_oDC);
	  l_poOldStretch = l_oDcStretch.SelectObject(mp_poStretchBmp); // Destination

#ifdef dCSP_VERTICAL_BAR
    if(mp_bVertical == TRUE)
    { // Vertical bar
      l_oDcVertical.CreateCompatibleDC(&l_oDC);
	    l_poOldVertical = l_oDcVertical.SelectObject(&l_oBmpVertical); // Destination
      l_oDcVertical.SetStretchBltMode(HALFTONE);
    }
    else
#endif // dCSP_VERTICAL_BAR
    { // Horizontal bar
      l_oDcStretch.SetStretchBltMode(HALFTONE);
    }

// C..... Copy the <mp_poCompatibleBmp> base bitmap and apply modifications to create an image list compatible bitmap
    // Copy the picture
#ifdef dCSP_VERTICAL_BAR
    if(mp_bVertical == TRUE)
    { // Vertical bar
      l_oDcVertical.StretchBlt
      ( 0
      , 0
      , l_sBmpSrc.bmWidth
#ifndef dCSP_DISPLAY_STRETCH
      , l_oRectBar.Width()  - 2
#else
      , l_oRectBar.Height() - 2
#endif // dCSP_DISPLAY_STRETCH
      , &l_oDcBitmap
      , 0
      , 0
      , l_sBmpSrc.bmWidth
      , l_sBmpSrc.bmHeight
      , SRCCOPY
      );

      // Copy the stretched vertical picture into the mp_poStretchBmp with part flip
      for
      ( int y = 0
#ifndef dCSP_DISPLAY_STRETCH
      ; y < l_oRectBar.Width()  - 2
#else
      ; y < l_oRectBar.Height() - 2
#endif // dCSP_DISPLAY_STRETCH
      ; y += 1
      )
      { // Scan each line
        for
        ( int x = 0
        ; x < l_sBmpSrc.bmWidth
        ; x += 1
        )
        { // Scan every pixel of the line
          l_oDcStretch.SetPixel
          (   y
            + (
                  (
#ifndef dCSP_DISPLAY_STRETCH
                      l_oRectBar.Width()
#else
                      l_oRectBar.Height()
#endif // dCSP_DISPLAY_STRETCH
                    - 2
                  )
                * (
                      x
                    / mp_nBmpWidth
                  )
              )
          , x % mp_nBmpWidth
          , l_oDcVertical.GetPixel(x, y)
          );
        }
      }
    }
    else
#endif // dCSP_VERTICAL_BAR
    { // Horizontal bar
#ifndef dCSP_CREATE_BITMAP_FILE
      l_oDcStretch.StretchBlt
      ( 0
      , 0
      , l_sBmpSrc.bmWidth
      , l_oRectBar.Height() - 2
      , &l_oDcBitmap
      , 0
      , 0
      , l_sBmpSrc.bmWidth
      , l_sBmpSrc.bmHeight
      , SRCCOPY
      );
#else
      l_oDcStretch.BitBlt
      ( 0
      , 0
      , l_sBmpSrc.bmWidth
      , l_sBmpSrc.bmHeight
      , &l_oDcBitmap
      , 0
      , 0
      , SRCCOPY
      ); // BITMAP CREATION IN CURRENT VIDEO MODE, PLEASE USE 32 BITS, AVOID MAPPED !
#endif //dCSP_CREATE_BITMAP_FILE
    }

    // Release the DC
#ifdef dCSP_VERTICAL_BAR
    if(mp_bVertical != FALSE)
    { // Vertical bar
	    l_oDcVertical.SelectObject(l_poOldVertical);
      l_oDcVertical.DeleteDC();
    }else{}
#endif // dCSP_VERTICAL_BAR

    l_oDcStretch.SelectObject(l_poOldStretch);
    l_oDcStretch.DeleteDC();

    l_oDcBitmap.SelectObject(l_poOldBitmap);
    l_oDcBitmap.DeleteDC();

// D..... Create the <mp_oBarImgLst> image list
// DA.... Get the stretched bitmap size
    // Get bitmap width and height for the image list creation
    mp_poStretchBmp->GetBitmap(&l_sBmpSrc);

#ifdef dCSP_CREATE_BITMAP_FILE
    // Fast and dirty routine to save the stretched bitmap in C format, for the people who wants to recreate the AQUA_BITMAP array with their own default bitmap, instead to provide it to the constructor
    FILE*          l_sFileHandle;
    unsigned char* l_panDataBmp;
    int            l_nCount = l_sBmpSrc.bmWidthBytes * l_sBmpSrc.bmHeight;
    unsigned char  l_nBufferHi;
    unsigned char  l_nBufferLo;
    int            l_nPointer;

    l_panDataBmp = new unsigned char[l_nCount];

    if(l_panDataBmp != NULL)
    {
      l_sFileHandle = fopen("C:\\aqua_bitmap.cpp", "wt"); // Change the path here
      if(l_sFileHandle != NULL)
      {
        mp_poStretchBmp->GetBitmapBits(l_nCount, l_panDataBmp);

        fprintf(l_sFileHandle, "unsigned char g_anAQUA_BITMAP[%d] =\n{\n ", l_nCount);

        for
        ( l_nPointer  = 0
        ; l_nPointer  < l_nCount
        ; l_nPointer += 1
        )
        {
          fputs(" 0x", l_sFileHandle);
          l_nBufferHi = l_panDataBmp[l_nPointer];
          l_nBufferLo = l_nBufferHi;

          l_nBufferHi >>= 4;
          l_nBufferLo  &= 0x0F;

          if(l_nBufferHi < 10)
          {
            l_nBufferHi += '0';
          }
          else
          {
            l_nBufferHi += 'A' - 10;
          }

          if(l_nBufferLo < 10)
          {
            l_nBufferLo += '0';
          }
          else
          {
            l_nBufferLo += 'A' - 10;
          }

          fputc(l_nBufferHi, l_sFileHandle);
          fputc(l_nBufferLo, l_sFileHandle);

          fputs(",", l_sFileHandle);

          if
          (
               (l_nPointer % 16)
            == 15
          )
          { // 16 pixels per line
            fputs("\n ", l_sFileHandle);
          }else{}
        }
        fputs("};\n\n", l_sFileHandle);

        fputs("BITMAP sAQUA_BITMAP =\n{\n", l_sFileHandle);
          fprintf(l_sFileHandle, "  %d,   // bmType\n",     l_sBmpSrc.bmType);
          fprintf(l_sFileHandle, "  %d,  // bmWidth\n",     l_sBmpSrc.bmWidth);
          fprintf(l_sFileHandle, "  %d,  // bmHeight\n",    l_sBmpSrc.bmHeight);
          fprintf(l_sFileHandle, "  %d, // bmWidthBytes\n", l_sBmpSrc.bmWidthBytes);
          fprintf(l_sFileHandle, "  %d,   // bmPlanes\n",   l_sBmpSrc.bmPlanes);
          fprintf(l_sFileHandle, "  %d,  // bmBitsPixel\n", l_sBmpSrc.bmBitsPixel);
          fputs("  g_anAQUA_BITMAP // bmBits\n", l_sFileHandle);
        fputs("};\n", l_sFileHandle);

        fclose(l_sFileHandle);
      }else{}

      delete l_panDataBmp;
    }else{}
#endif //dCSP_CREATE_BITMAP_FILE

    // Image list creation

// DB.... Calculate the size of every element of the image list
    mp_nBmpWidth  = l_sBmpSrc.bmWidth / cSPB_EnumElements; // cSPB_EnumElements == 5, the bitmap is yet composed of 5 parts
    mp_nBmpHeight = l_sBmpSrc.bmHeight;

// DC.... Delete the previous image list the create a new one from scratch (useful when providing a new bitmap during SkinProgress life-time)
    mp_oBarImgLst.DeleteImageList(); // Delete the previous ImageList and recreate it with the new bitmap

// DD.... Create the new image list in 32 bits to be sure it will accept any kind of bitmap in input (if 8 bits bitmap provided, will be converted in 32 bits)
    if
    (
         mp_oBarImgLst.Create
         ( mp_nBmpWidth
         , mp_nBmpHeight
         , ILC_COLOR32 // ILC_COLOR32 to be sure to accept any BitMap format passed through i_poBitmap
         , 0
         , 0
         )
      == FALSE
    )
    {
      return FALSE;
    }
    else
    {
// DE.... Add the stretched bitmap in the image list
      mp_oBarImgLst.Add
      ( mp_poStretchBmp
      , RGB(0, 255, 255) // SKY BLUE
      );

// E..... Display the new bitmap
#ifndef dCSP_TIMED_REDRAW
      if(i_bDisplay != FALSE)
      {
        RefreshPanes();
      }else{}
#endif // dCSP_TIMED_REDRAW

      return TRUE;
    }
  }
  else
  {
    return FALSE;
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : CopyBitmap                                                 */
/* Role          : Copy a bitmap                                              */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : Error in copy                             */
/*                          TRUE  : Image copied                              */
/*                 OUTPUT (pointer to value)                                  */
/*                   o_poBitmap    : Image where to copy                      */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_poBitmap    : Image to copy                            */
/* Pre-condition : Both output and input pointer must be provided !           */
/*                 Also, the output bitmap MUST BE CREATED, BUT NOT           */
/*                 INITIALIZED                                                */
/* Constraints   : Do not handle mapped bitmap yet...                         */
/* Behavior      : A - Create a remote data buffer to get the source data     */
/*                 B - Get the source data                                    */
/*                 C - Copy the bitmap                                        */
/*----------------------------------------------------------------------------*/
/* PROC CopyBitmap                                                            */
/*                                                                            */
/* A..... Create a remote data buffer to get the source data                  */
/* [IF the remote buffer is successfully created]                             */
/* : B..... Get the source data                                               */
/* : C..... Copy the bitmap                                                   */
/* [ENDIF]                                                                    */
/*----------------------------------------------------------------------------*/
/* As this STUPID [CBitmap::GetBitmap((BITMAP*) o_psBitmap)] returns NULL in  */
/* <o_psBitmap.bmBits>, we cannot reuse immediatly the returned BITMAP for a  */
/* [CBitmap::CreateBitmapIndirect((BITMAP*) i_psBitmap)], we have to get the  */
/* address of the data buffer by creating it by ourself, then get the datas   */
/* with [CBitmap::GetBitmapBits((DWORD) i_nDataCount, (LPVOID) i_panDataBmp)] */
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CSkinProgress::CopyBitmap
( CBitmap* o_poBitmap // Pointer to an EXISTING but NOT INITIALIZED bitmap
, CBitmap* i_poBitmap // Pointer to the source bitmap
)
{ // Copy a bitmap 
  BITMAP         l_sBmpSrc;
  unsigned char* l_panDataBmp;
  DWORD          l_nDataCount;
  BOOL           l_bResult;

  // Init

  // Process

  if
  (
       (o_poBitmap == NULL)
    || (i_poBitmap == NULL)
  )
  {
    return FALSE;
  }
  else
  {
// A..... Create a remote data buffer to get the source data
    i_poBitmap->GetBitmap(&l_sBmpSrc);

    l_nDataCount = l_sBmpSrc.bmWidthBytes * l_sBmpSrc.bmHeight;
    l_panDataBmp = new unsigned char[l_nDataCount];

    if(l_panDataBmp != NULL)
    {
// B..... Get the source data
      i_poBitmap->GetBitmapBits(l_nDataCount, l_panDataBmp);
      l_sBmpSrc.bmBits = l_panDataBmp; // Just complete the BITMAP structure

// C..... Copy the bitmap
      l_bResult = o_poBitmap->CreateBitmapIndirect(&l_sBmpSrc);

      delete[] l_panDataBmp;

      return l_bResult;
    }
    else
    {
      return FALSE;
    }
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : ConvBitmap                                                 */
/* Role          : Convert a bitmap to a specified device context             */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : Error in conversion                       */
/*                          TRUE  : Image converted                           */
/*                 OUTPUT (pointer to value)                                  */
/*                   o_poBitmap    : Image where to copy/transform            */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_poBitmap    : Image to copy/transform                  */
/*                   i_poDC        : The DC to use for the conversion         */
/* Pre-condition : Both output and input pointer must be provided !           */
/*                 Also, the output bitmap MUST BE CREATED, BUT NOT           */
/*                 INITIALIZED                                                */
/* Constraints   : Do not handle mapped bitmap yet...                         */
/* Behavior      : A - Get the current DC                                     */
/*                 B - Copy the bitmap                                        */
/*                 C - Create a remote data buffer to get the source data     */
/*                 D - Get the source data                                    */
/*                 E - Initialize the bitmap                                  */
/*                 F - Convert the data                                       */
/*                 G - Copy the converted bitmap                              */
/*----------------------------------------------------------------------------*/
/* PROC CopyBitmap                                                            */
/*                                                                            */
/* [IF pointers on bitmap valids]                                             */
/* : [IF no DC provided]                                                      */
/* : : A..... Get the current DC                                              */
/* : [ELSE]                                                                   */
/* : [IF same color format]                                                   */
/* : : B..... Copy the bitmap                                                 */
/* : [ELSE]                                                                   */
/* : : C..... Create a remote data buffer to get the source data              */
/* : : [IF buffer created]                                                    */
/* : : : D..... Get the source data                                           */
/* : : : E..... Initialize the bitmap                                         */
/* : : : F..... Convert the data                                              */
/* : : : G..... Copy the converted bitmap                                     */
/* : : [ELSE]                                                                 */
/* : [ENDIF]                                                                  */
/* [ENDIF]                                                                    */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CSkinProgress::ConvBitmap
( CBitmap*    o_poBitmap // Pointer to an EXISTING but NOT INITIALIZED bitmap
, CBitmap*    i_poBitmap // Pointer to the source bitmap
, CDC*        i_poDC     // = NULL : Pointer to the DC to use for the conversion, if NULL use the current DC
)
{ // Convert a bitmap to a specified device context
  BITMAP         l_sBmpSrc;
  BITMAPINFO     l_sBmpInfoSrc;
  HBITMAP        l_hDIB;
  unsigned char* l_panDataBmp;
  DWORD          l_nDataCount;
  int            l_nResult;

  // Init

  l_panDataBmp = NULL;

  // Process

  if
  (
       (o_poBitmap != NULL)
    && (i_poBitmap != NULL)
  )
  {
    if(i_poDC == NULL)
    { // If no target device context provided, use the current one
// A..... Get the current DC
      CClientDC l_oDC(this);
      i_poDC = &l_oDC;
    }else{}

    i_poBitmap->GetBitmap(&l_sBmpSrc); // Get some infos on the source bitmap

    if(l_sBmpSrc.bmBitsPixel == GetDeviceCaps(*i_poDC, BITSPIXEL))
    { // If it's the same bitmap format, just copy it instead to waste some time to convert the picture (what will fail :/ )
// B..... Copy the bitmap
      l_nResult = (int) CopyBitmap(o_poBitmap, i_poBitmap);
    }
    else
    {
// C..... Create a remote data buffer to get the source data
      l_nDataCount = l_sBmpSrc.bmWidthBytes * l_sBmpSrc.bmHeight;
      l_panDataBmp = new unsigned char[l_nDataCount];

      if(l_panDataBmp != NULL)
      {
// D..... Get the source data
        i_poBitmap->GetBitmapBits(l_nDataCount, l_panDataBmp);
        l_sBmpSrc.bmBits = l_panDataBmp;

// E..... Initialize the bitmap

        l_sBmpInfoSrc.bmiColors[0].rgbBlue      = 0;
        l_sBmpInfoSrc.bmiColors[0].rgbGreen     = 0;
        l_sBmpInfoSrc.bmiColors[0].rgbRed       = 0;
        l_sBmpInfoSrc.bmiColors[0].rgbReserved  = 0;

        l_sBmpInfoSrc.bmiHeader.biSize          = sizeof(BITMAPINFOHEADER);
        l_sBmpInfoSrc.bmiHeader.biWidth         = l_sBmpSrc.bmWidth;
        l_sBmpInfoSrc.bmiHeader.biHeight        = 0 - l_sBmpSrc.bmHeight; // 0 - HEIGHT : TOP-DOWN l_hDIB, origin is upper/left corner
        l_sBmpInfoSrc.bmiHeader.biPlanes        = l_sBmpSrc.bmPlanes;
        l_sBmpInfoSrc.bmiHeader.biBitCount      = l_sBmpSrc.bmBitsPixel;
        l_sBmpInfoSrc.bmiHeader.biCompression   = BI_RGB;
        l_sBmpInfoSrc.bmiHeader.biSizeImage     = 0; // 0 : BI_RGB
        l_sBmpInfoSrc.bmiHeader.biXPelsPerMeter = 0;
        l_sBmpInfoSrc.bmiHeader.biYPelsPerMeter = 0;
        l_sBmpInfoSrc.bmiHeader.biClrUsed       = 0;
        l_sBmpInfoSrc.bmiHeader.biClrImportant  = 0;

// F..... Convert the data
        l_hDIB = CreateDIBitmap
        ( i_poDC->m_hDC
        , &l_sBmpInfoSrc.bmiHeader
        , CBM_INIT
        , l_panDataBmp
        , &l_sBmpInfoSrc
        , DIB_RGB_COLORS
        );

// G..... Copy the converted bitmap
        l_nResult
        = (int) 
          CopyBitmap
          ( o_poBitmap
          , CBitmap::FromHandle(l_hDIB)
          )
        ;

        DeleteObject(l_hDIB);
        delete[] l_panDataBmp;

        if(l_nResult != 0)
        {
          return TRUE;
        }else{}
      }else{}
    }
  }else{}

  return FALSE;
}

// *** PROGRESS INTERFACE ***

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : SetRange                                                   */
/* Role          : None                                                       */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : Error while trying to change the range    */
/*                          TRUE  : New range set                             */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_nLower    : Minimum value possible                     */
/*                   i_nUpper    : Maximum value possible                     */
/*                   i_nStep     : Step increment                             */
/*                   i_bResamble : Resample the current position              */
/*                   i_bDisplay  : Display the changes                        */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Resample the postion                                   */
/*                 B - Set the new range                                      */
/*                 C - Display the new ranged progress bar                    */
/*----------------------------------------------------------------------------*/
/* PROC SetRange                                                              */
/*                                                                            */
/* A..... Resample the postion from the previous range to the new one         */
/* B..... Set the new range values                                            */
/* C..... Display the new ranged progress bar                                 */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CSkinProgress::SetRange
( int  i_nLower    // Minimum limit
, int  i_nUpper    // Maximum limit
, int  i_nStep     // = 1     : Step increment
, BOOL i_bResamble // = FALSE : Resample the current position from the new Lower and Upper values
#ifndef dCSP_TIMED_REDRAW
, BOOL i_bDisplay  // = TRUE  : Display the changes
#endif // dCSP_TIMED_REDRAW
)
{ // Set the new range

  // Init

  // Process + Return

  if(IsWindow(GetSafeHwnd()))
  {
    ASSERT((-0x7FFFFFFF <= i_nLower) && (i_nLower <= 0x7FFFFFFF));
    ASSERT((-0x7FFFFFFF <= i_nUpper) && (i_nUpper <= 0x7FFFFFFF));
    ASSERT(i_nLower < i_nUpper); // Seems to be stupid, but avoid zero divide problem in percent calculation just below

// A..... Resample the postion from the previous range to the new one
    if(i_bResamble != FALSE)
    { // Resample positions to readapt them to the new range
#ifdef dCSP_SLIDERBAR_METHOD
      // Recalculate start
      mp_nLeft
      = (int)
        (
          (
            ( (LONGLONG) // Turns the whole calculation in 64 bits
              (mp_nLeft  - mp_nLower) // Old start
              * (i_nUpper - i_nLower) // New range
            )
            / (mp_nUpper - mp_nLower)     // Old range
          )
          + i_nLower                      // New start
        )
      ;

      mp_nPrevLeft  = mp_nLeft;
#endif // dCSP_SLIDERBAR_METHOD

      // Recalculate end
      mp_nRight
      = (int)
        (
          (
            ( (LONGLONG) // Turns the whole calculation in 64 bits
              (mp_nRight - mp_nLower) // Old end
              * (i_nUpper - i_nLower) // New range
            )
            / (mp_nUpper - mp_nLower)     // Old range
          )
          + i_nLower                      // New end 
        )
      ;

      mp_nPrevRight = mp_nRight;
    }else{}

// B..... Set the new range values
    // Sets new parameters for good
    mp_nLower = i_nLower;
    mp_nUpper = i_nUpper;
    mp_nStep  = i_nStep;

// C..... Display the new ranged progress bar
#ifndef dCSP_TIMED_REDRAW
    if(i_bDisplay != FALSE)
    {
      RefreshPanes();
    }else{}
#endif // dCSP_TIMED_REDRAW

    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : SetPos                                                     */
/* Role          : None                                                       */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   int : Previous <mp_nRight> position, 0 if error          */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_nPos     : Select the new position                     */
/*                   i_bDisplay : Display the changes                         */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Jump to a specified position                           */
/*                 B - Display the changes                                    */
/*                 C - Return the previous position                           */
/*----------------------------------------------------------------------------*/
/* PROC SetPos                                                                */
/*                                                                            */
/* A..... Jump to a specified <i_nEnd> position                               */
/* B..... Display the changes                                                 */
/* C..... Return the previous <mp_nRight> position                            */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CSkinProgress::SetPos
(  int  i_nPos    // Set a new current position
#ifndef dCSP_TIMED_REDRAW
, BOOL i_bDisplay // = TRUE : Display the changes
#endif // dCSP_TIMED_REDRAW
)
{ // Set <mp_nRight> value

  // Init

  // Process + Return

  if(IsWindow(GetSafeHwnd()))
  {
    ASSERT((-0x7FFFFFFF <= i_nPos) && (i_nPos <= 0x7FFFFFFF));

    if(i_nPos > mp_nUpper)
    { // Avoid problems
      i_nPos = mp_nUpper;
    }else{}

    if(i_nPos < mp_nLower)
    { // Avoid problems
      i_nPos = mp_nLower;
    }else{}

#ifdef dCSP_SLIDERBAR_METHOD
    if(i_nPos < mp_nLeft)
    { // Avoid problems
      i_nPos = mp_nLeft;
    }else{}
#endif // dCSP_SLIDERBAR_METHOD

    mp_nPrevRight = mp_nRight;
// A..... Jump to a specified <i_nEnd> position
    mp_nRight     = i_nPos;

// B..... Display the changes
#ifndef dCSP_TIMED_REDRAW
    if(i_bDisplay != FALSE)
    {
      RefreshPanes();
    }else{}
#endif // dCSP_TIMED_REDRAW

// C..... Return the previous <mp_nRight> position
    return mp_nPrevRight;
  }
  else
  {
    return 0;
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : OffsetPos                                                  */
/* Role          : None                                                       */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   int : Previous <mp_nRight> position, 0 if error          */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_nOffset  : Offset the current position                 */
/*                   i_bDisplay : Display the changes                         */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Add an offset to the current position                  */
/*                 B - Display the changes                                    */
/*                 C - Return the previous position                           */
/*----------------------------------------------------------------------------*/
/* PROC OffsetPos                                                             */
/*                                                                            */
/* A..... Add a <i_nEnd> offset to the current <mp_nRight> position           */
/* B..... Display the changes                                                 */
/* C..... Return the previous <mp_nRight> position                            */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CSkinProgress::OffsetPos
( int  i_nOffset  // Add the offset to the current position (can be negative)
#ifndef dCSP_TIMED_REDRAW
, BOOL i_bDisplay // = TRUE : Display the changes
#endif // dCSP_TIMED_REDRAW
)
{ // Forward of <i_nOffset> value

  // Init

  // Process + Return

  if(IsWindow(GetSafeHwnd()))
  {
    mp_nPrevRight  = mp_nRight;
// A..... Add a <i_nEnd> offset to the current <mp_nRight> position
    mp_nRight     += i_nOffset;

    if(mp_nRight > mp_nUpper)
    { // Avoid problems
      mp_nRight = mp_nUpper;
    }else{}

    if(mp_nRight < mp_nLower)
    { // Avoid problems
      mp_nRight = mp_nLower;
    }else{}

#ifdef dCSP_SLIDERBAR_METHOD
    if(mp_nRight < mp_nLeft)
    { // Avoid problems
      mp_nRight = mp_nLeft;
    }else{}
#endif // dCSP_SLIDERBAR_METHOD

// B..... Display the changes
#ifndef dCSP_TIMED_REDRAW
    if(i_bDisplay != FALSE)
    {
      RefreshPanes();
    }else{}
#endif // dCSP_TIMED_REDRAW

// C..... Return the previous <mp_nRight> position
    return mp_nPrevRight;
  }
  else
  {
    return 0;
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : SetStep                                                    */
/* Role          : None                                                       */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   int : Previous <mp_nStep> setting, 0 if error            */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_nStep : Set the new step increment                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Set the step increment value                           */
/*                 B - Return the previous step increment value               */
/*----------------------------------------------------------------------------*/
/* PROC SetStep                                                               */
/*                                                                            */
/* A..... Set the <mp_nStep> step increment value                             */
/* C..... Return the previous <mp_nStep> step increment value                 */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CSkinProgress::SetStep
( int i_nStep // Set the step increment
)             
{ // Set <mp_nStep> value
  int l_nPrevStep;

  // Init

  // Process + Return

  if(IsWindow(GetSafeHwnd()))
  {
    l_nPrevStep = mp_nStep;
// A..... Set the <mp_nStep> step increment value
    mp_nStep    = i_nStep;

// B..... Return the previous <mp_nStep> step increment value
    return l_nPrevStep;
  }
  else
  {
    return 0;
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : StepIt                                                     */
/* Role          : None                                                       */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   int : Previous <mp_nRight> position, 0 if error          */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_bDisplay : Display the changes                         */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Step the position                                      */
/*                 B - Display the changes                                    */
/*                 C - Return the previous position                           */
/*----------------------------------------------------------------------------*/
/* PROC StepIt                                                                */
/*                                                                            */
/* A..... Step the <mp_nRight> position from the <mp_nStep> increment value   */
/* B..... Display the changes                                                 */
/* C..... Return the previous <mp_nRight> position                            */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CSkinProgress::StepIt
(
#ifndef dCSP_TIMED_REDRAW
  BOOL i_bDisplay // = TRUE : Display the changes
#endif // dCSP_TIMED_REDRAW
) 
{ // Forward of <mp_nStep> value 

  // Init

  // Process + Return

  if(IsWindow(GetSafeHwnd()))
  {
    mp_nPrevRight  = mp_nRight;
// A..... Step the <mp_nRight> position from the <mp_nStep> step increment value
    mp_nRight     += mp_nStep;

    if(mp_nRight > mp_nUpper)
    { // Avoid problems
      mp_nRight = mp_nUpper;
    }else{}

    if(mp_nRight < mp_nLower)
    { // Avoid problems
      mp_nRight = mp_nLower;
    }else{}

#ifdef dCSP_SLIDERBAR_METHOD
    if(mp_nRight < mp_nLeft)
    { // Avoid problems
      mp_nRight = mp_nLeft;
    }else{}
#endif // dCSP_SLIDERBAR_METHOD

// B..... Display the changes
#ifndef dCSP_TIMED_REDRAW
    if(i_bDisplay != FALSE)
    {
      RefreshPanes();
    }else{}
#endif // dCSP_TIMED_REDRAW

// C..... Return the previous <mp_nRight> position
    return mp_nPrevRight;
  }
  else
  {
    return 0;
  }
}

// *** EXTENDED PROGRESS INTERFACE ***

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : SetSize                                                    */
/* Role          : Change the size of the progress bar if in pane 0           */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : NEVER                                     */
/*                          TRUE  : ALWAYS                                    */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_nSize    : The new size of the progress bar in pane 0  */
/*                   i_bDisplay : Display the changes                         */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Set the new size of the progress bar                   */
/*                 B - Display the resized progress bar                       */
/*----------------------------------------------------------------------------*/
/* PROC SetSize                                                               */
/*                                                                            */
/* A..... Set the new size of the progress bar                                */
/* B..... Display the resized progress bar                                    */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CSkinProgress::SetSize
( int  i_nSize     // Set the size of the progress bar
#ifndef dCSP_TIMED_REDRAW
, BOOL i_bDisplay // = TRUE : Display the changes
#endif // dCSP_TIMED_REDRAW
)
{ // Set size of the progress bar in pane 0

  // Init

// A..... Set the new size of the progress bar
  if(i_nSize > 0)
  { // Due to pane anti-disclosure system and progress bar contour, must readapt the size
    i_nSize += 5;
  }
  else if(i_nSize < 0)
  {
    i_nSize -= 2;
  }else{}

  mp_nSize = i_nSize;

  // Process

// B..... Display the resized progress bar
#ifndef dCSP_TIMED_REDRAW
  if(i_bDisplay != FALSE)
  {
    RefreshPanes();
  }else{}
#endif // dCSP_TIMED_REDRAW

  // Return

  return TRUE;
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : GetSize                                                    */
/* Role          : Get width or height of the progress bar                    */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   int : The width or height in pixel of the progress bar   */
/*                     0 : Error                                              */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Return the current <mp_nSize> value                    */
/*                 B - Return the CWnd based pane size                        */
/*----------------------------------------------------------------------------*/
/* PROC SetStart                                                              */
/*                                                                            */
/* [IF progress bar in status bar]                                            */
/* : A..... Return the current <mp_nSize> value                               */
/* [ELSE]                                                                     */
/* : [IF get the target pane rectangle]                                       */
/* : : B..... Return the CWnd based pane size                                 */
/* : : [IF the bar is not vertical]                                           */
/* : : : BA.... Return the width                                              */
/* : : [ELSE]                                                                 */
/* : : : BB.... Return the height                                             */
/* ; : [ENDIF]                                                                */
/* : [ELSE]                                                                   */
/* :   [ERROR]                                                                */
/* ; [ENDIF]                                                                  */
/* [ENDIF]                                                                    */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CSkinProgress::GetSize
(
)
{ // Get width or height of the progress bar in pixel, mostly used in CSkinSlider
#ifdef dCSP_DIALOG_PROGRESS
  CRect l_oRectPane;

  // Init

  // Process + Return

  if(mp_poWndProgress == NULL)
  {
#endif // dCSP_DIALOG_PROGRESS
// A..... Return the current <mp_nSize> value
    return mp_nSize;
#ifdef dCSP_DIALOG_PROGRESS
  }
  else
  {
// B..... Return the CWnd based pane size
    if(_GetTargetRect(&l_oRectPane))
    {
#ifdef dCSP_VERTICAL_BAR
      if(mp_bVertical == TRUE)
      { // Vertical Bar
        return l_oRectPane.Height();
      }
      else
#endif // dCSP_VERTICAL_BAR
      { // Horizontal Bar
        return l_oRectPane.Width();
      }
    }
    else
    {
      return 0;
    }
  }
#endif // dCSP_DIALOG_PROGRESS
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : GetPos                                                     */
/* Role          : Get <mp_nRight> value                                      */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   int : Current <mp_nRight> position                       */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_bPercent : Return the position in percent              */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Return the current <mp_nRight> position                */
/*                 B - Return the current <mp_nRight position in percent      */
/*----------------------------------------------------------------------------*/
/* PROC SetStart                                                              */
/*                                                                            */
/* [IF normal mode]                                                           */
/* : A..... Return the current <mp_nRight> position                           */
/* [ELSE]                                                                     */
/* : B..... Return the current <mp_nRight> position in percent                */
/* [ENDIF]                                                                    */
/*----------------------------------------------------------------------------*/
/* If return in percent, 90% gives 23040, divided by 256 (>> 8) returns 90 !  */
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CSkinProgress::GetPos
( BOOL i_bPercent // = FALSE
)
{ // Get <mp_nRight> value
  if(i_bPercent == FALSE)
  {
// A..... Return the current <mp_nRight> position
    return mp_nRight;
  }
  else
  {
// B..... Return the current <mp_nRight> position in 8-bits fixed point percent value ('>> 8' to get the 'int' value)
    return (int)
    ( // 100% *256 to keep a pseudo 8-bits fixed point value (0.00390625 - 1/256 - resolution)
      ( (LONGLONG) // Turns the whole calculation in 64 bits
        (mp_nRight - mp_nLower)
        * 25600
      )
      / (mp_nUpper - mp_nLower)
    );
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : GetStep                                                    */
/* Role          : Get <mp_nStep> value                                       */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   int : Current <mp_nStep> value                           */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Return the current <mp_nStep> value                    */
/*----------------------------------------------------------------------------*/
/* PROC SetStart                                                              */
/*                                                                            */
/* A..... Return the current <mp_nStep> value                                 */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CSkinProgress::GetStep
(
)
{ // Get <mp_nStep> value
// A..... Return the current <mp_nStep> value
  return mp_nStep;
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : GetLower                                                   */
/* Role          : Get <mp_nLower> value                                      */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   int : Current <mp_nLower> value                          */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Return the current <mp_nLower> value                   */
/*----------------------------------------------------------------------------*/
/* PROC SetStart                                                              */
/*                                                                            */
/* A..... Return the current <mp_nLower> value                                */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CSkinProgress::GetLower
(
)
{ // Get <mp_nLower> value
// A..... Return the current <mp_nLower> value
  return mp_nLower;
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : GetUpper                                                   */
/* Role          : Get <mp_nUpper> value                                      */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   int : Current <mp_nUpper> value                          */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Return the current <mp_nUpper> value                   */
/*----------------------------------------------------------------------------*/
/* PROC SetStart                                                              */
/*                                                                            */
/* A..... Return the current <mp_nUpper> value                                */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CSkinProgress::GetUpper
(
)
{ // Get <mp_nUpper> value
// A..... Return the current <mp_nUpper> value
  return mp_nUpper;
}

#ifdef dCSP_SLIDERBAR_METHOD
/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : SetStart                                                   */
/* Role          : None                                                       */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   int : Previous <mp_nLeft> position, 0 if error           */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_nStart   : Select the new start position               */
/*                   i_bDisplay : Display the changes                         */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Jump to a specified position                           */
/*                 B - Display the changes                                    */
/*                 C - Return the previous position                           */
/*----------------------------------------------------------------------------*/
/* PROC SetStart                                                              */
/*                                                                            */
/* A..... Jump to a specified <i_nStart> position                             */
/* B..... Display the changes                                                 */
/* C..... Return the previous <mp_nLeft> position                             */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CSkinProgress::SetStart
( int  i_nStart   // Set a new start position
#ifndef dCSP_TIMED_REDRAW
, BOOL i_bDisplay // = TRUE : Display the changes
#endif // dCSP_TIMED_REDRAW
)
{ // Set <mp_nLeft> value

  // Init

  // Process + Return

  if(IsWindow(GetSafeHwnd()))
  {
    ASSERT((-0x7FFFFFFF <= i_nStart) && (i_nStart <= 0x7FFFFFFF));

    if(i_nStart > mp_nUpper)
    { // Avoid problems
      i_nStart = mp_nUpper;
    }else{}

    if(i_nStart < mp_nLower)
    { // Avoid problems
      i_nStart = mp_nLower;
    }else{}

    if(i_nStart > mp_nRight)
    { // Avoid problems
      i_nStart = mp_nRight;
    }else{}

    mp_nPrevLeft = mp_nLeft;
// A..... Jump to a specified <i_nEnd> position
    mp_nLeft     = i_nStart;

// B..... Display the changes
#ifndef dCSP_TIMED_REDRAW
    if(i_bDisplay != FALSE)
    {
      RefreshPanes();
    }else{}
#endif // dCSP_TIMED_REDRAW

// C..... Return the previous <mp_nPrevLeft> position
    return mp_nPrevLeft;
  }
  else
  {
    return 0;
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : GetStart                                                   */
/* Role          : Get <mp_nLeft> value                                       */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   int : Current <mp_nLeft> position                        */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_bPercent : Return the position in percent              */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Return the current <mp_nLeft> position                 */
/*                 B - Return the current <mp_nLeft> position in percent      */
/*----------------------------------------------------------------------------*/
/* PROC SetStart                                                              */
/*                                                                            */
/* [IF normal mode]                                                           */
/* : A..... Return the current <mp_nLeft> position                            */
/* [ELSE]                                                                     */
/* : B..... Return the current <mp_nLeft> position in percent                 */
/* [ENDIF]                                                                    */
/*----------------------------------------------------------------------------*/
/* If return in percent, 90% gives 23040, divided by 256 (>> 8) returns 90 !  */
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CSkinProgress::GetStart
( BOOL i_bPercent // = FALSE
)
{ // Get <mp_nLeft> value
  if(i_bPercent == FALSE)
  {
// A..... Return the current <mp_nLeft> position
    return mp_nLeft;
  }
  else
  {
// B..... Return the current <mp_nLeft> position in 8-bits fixed point percent value ('>> 8' to get the 'int' value)
    return (int)
    ( // 100% *256 to keep a pseudo 8-bits fixed point value (0.00390625 - 1/256 - resolution)
      ( (LONGLONG) // Turns the whole calculation in 64 bits
        (mp_nLeft - mp_nLower)
        * 25600
      )
      / (mp_nUpper - mp_nLower)
    );
  }
}
#endif // dCSP_SLIDERBAR_METHOD

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : Reset                                                      */
/* Role          :  // Restart the progress bar                               */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_bDisplay : Display the changes                         */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Get the creation date and time of the progress bar     */
/*                 B - Set the position of the bar to its beginning           */
/*----------------------------------------------------------------------------*/
/* PROC StepIt                                                                */
/*                                                                            */
/* A..... Get the creation date and time of the progress bar                  */
/* B..... Set the position of the bar to its beginning                        */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
void CSkinProgress::Reset
(
#ifndef dCSP_TIMED_REDRAW
  BOOL i_bDisplay // = TRUE : Display the changes
#endif // dCSP_TIMED_REDRAW
)
{ // Restart the progress bar
  FILETIME sStartTimeFile;

  // Init

  // Process

// A..... Get the creation date and time of the progress bar
//  GetSystemTime(&mp_sStartTimeSystem);
  GetLocalTime(&mp_sStartTimeSystem);
  SystemTimeToFileTime(&mp_sStartTimeSystem, &sStartTimeFile);

  mp_nStartTimeLongLong
  = ( (LONGLONG) // Turns the whole calculation in 64 bits
      sStartTimeFile.dwHighDateTime
      << 32
    )
  | sStartTimeFile.dwLowDateTime
  ;

// B..... Set the position of the bar to its beginning
  SetPos
  ( mp_nLower
#ifndef dCSP_TIMED_REDRAW
  , i_bDisplay
#endif // dCSP_TIMED_REDRAW
  );
}

// *** TEXT INTERFACE ***

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : SetText                                                    */
/* Role          : Change the text                                            */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : NEVER                                     */
/*                          TRUE  : ALWAYS                                    */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_poStrMessage : New text to display                     */
/*                   i_bDisplay    : Display the changes                      */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Set the new text                                       */
/*                 B - Display the new text                                   */
/*----------------------------------------------------------------------------*/
/* PROC SetText                                                               */
/*                                                                            */
/* A..... Set the new text                                                    */
/* B..... Display the changes                                                 */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CSkinProgress::SetText
( LPCTSTR i_poStrMessage  // New text to display      
#ifndef dCSP_TIMED_REDRAW
, BOOL    i_bDisplay      // = TRUE : Display the changes
#endif // dCSP_TIMED_REDRAW
)
{ // Set the new text

  // Init

// A..... Set the new text
  mp_oStrMessage = i_poStrMessage;

  // Process

// B..... Display the changes
#ifndef dCSP_TIMED_REDRAW
  if(i_bDisplay != FALSE)
  {
    RefreshPanes();
  }else{}
#endif // dCSP_TIMED_REDRAW

  // Return

  return TRUE;
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : SetProgress                                                */
/* Role          : Change the completion status text                          */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : NEVER                                     */
/*                          TRUE  : ALWAYS                                    */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_nProgress : Any <eProgressSkinText> entry value        */
/*                   i_bDisplay  : Display the changes                        */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Set the new progress text                              */
/*                 B - Display the new progress text                          */
/*----------------------------------------------------------------------------*/
/* PROC SetProgress                                                           */
/*                                                                            */
/* A..... Set the new progress text                                           */
/* B..... Display the new progress text                                       */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CSkinProgress::SetProgress
( int  i_nProgress  // Set progress text
#ifndef dCSP_TIMED_REDRAW
, BOOL i_bDisplay   // = TRUE : Display the changes
#endif // dCSP_TIMED_REDRAW
)
{ // Set <mp_nProgressText> value

  // Init

// A..... Set the new progress text
  mp_nProgressText = i_nProgress;

  // Process

// B..... Display the resized progress bar
#ifndef dCSP_TIMED_REDRAW
  if(i_bDisplay != FALSE)
  {
    RefreshPanes();
  }else{}
#endif // dCSP_TIMED_REDRAW

  // Return

  return TRUE;
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : GetProgress                                                */
/* Role          : Get the completion status message currently used           */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   int : The current <mp_nProgressText> value               */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Return the current <mp_nProgressText> value            */
/*----------------------------------------------------------------------------*/
/* PROC GetProgress                                                           */
/*                                                                            */
/* A..... Return the current <mp_nProgressText> value                         */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CSkinProgress::GetProgress
(
)
{ // Get <mp_nProgressText> value

  // Init

  // Process

  // Return

// A..... Return the current <mp_nProgressText> value
  return mp_nProgressText;
}

// *** UPDATE PROCESS ***

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : RefreshPanes                                               */
/* Role          : None                                                       */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : Error while trying to resize the text     */
/*                          TRUE  : Process completed without error           */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Get the text pane pointer and dimension                */
/*                 B - Progress pane size calculation                         */
/*                 C - Get optional message length                            */
/*                 D - Compact the text in the remaining space                */
/*                 E - Create the complete information message                */
/*                 F - Modify the progress bar size according of its size     */
/*                 G - Refresh the progress bar                               */
/*                 H - Display the complete information message               */
/*----------------------------------------------------------------------------*/
/* PROC RefreshPanes                                                          */
/*                                                                            */
/* A..... Get the text pane pointer and dimension                             */
/* [IF it is in dialog mode, in a CWnd target pane]                           */
/* : [IF there is a CWnd text pane]                                           */
/* : : AA.... Dialog CWnd text anchor                                         */
/* : [ENDIF]                                                                  */
/* [ELSE]                                                                     */
/* : [IF there is a status bar]                                               */
/* : : AB.... Status bar pane 0                                               */
/* : [ENDIF]                                                                  */
/* [ENDIF]                                                                    */
/* B..... Progress pane size calculation                                      */
/* [IF the progress bar dimension is valid]                                   */
/* : BA.... Set the size of the progress bar to the full width of its pane    */
/* : [IF there is a text pane]                                                */
/* : : BB.... Get text pane's DC                                              */
/* : : [IF text in status bar]                                                */
/* : : : BC.... Calculate the fixed size of the progress bar                  */
/* : : : [IF progress in pane 0 and have a fixed size]                        */
/* : : : : [IF size > 0]                                                      */
/* : : : : : BCA... Calculate the remaining size for the text                 */
/* : : : : [ELSE]                                                             */
/* : : : : : BCB... Calculate the size of the text to use                     */
/* : : : : [ENDIF]                                                            */
/* : : : [ELSE]                                                               */
/* : : : : BCC... Use whole width of pane 0 for the text                      */
/* : : : [ENDIF]                                                              */
/* : : [ELSE]                                                                 */
/* : : : BD.... Use all the space of the CWnd text anchor                     */
/* : : [ENDIF]                                                                */
/* : : [IF text is visble]                                                    */
/* : : : C..... Get optional message length                                   */
/* : : : [IF there is a message to add]                                       */
/* : : : : CA.... Get the length of the cSPT_PERCENT message                  */
/* : : : : [IF the message is at least TIMED]                                 */
/* : : : : : CB.... Get the length of the cSPT_TIMED message                  */
/* : : : : [ENDIF]                                                            */
/* : : : [ENDIF]                                                              */
/* : : : CC.... Get the length of the text to display                         */
/* : : : D..... Compact the text in the remaining space                       */
/* : : : [IF there is no message]                                             */
/* : : : : DA.... Compact the text according to just its length               */
/* : : : [ELSE]                                                               */
/* : : : : DB.... Compact the text minus the length of the cSPT_PERCENT       */
/* : : : [ELSE]                                                               */
/* : : : : DC.... Compact the text minus the length of the cSPT_TIMED         */
/* : : : [ELSE]                                                               */
/* : : : : DD.... Compact the text according to the remaining place           */
/* : : : : [IF the message is at least TIMED]                                 */
/* : : : : : DDA... Try to compact the text with cSPT_TIMED at first          */
/* : : : : [ELSE]                                                             */
/* : : : : : [IF the message is at least TIMED]                               */
/* : : : : : : DDB... Reset the text                                          */
/* : : : : : : DDC... Calculate the length of the three dots                  */
/* : : : : : : DDD... Compact the text minus the three doted cSPT_PERCENT     */
/* : : : : : : DDE... Indicate the message used is cRTP_PERCENT               */
/* : : : : : [ELSE]                                                           */
/* : : : : : : DDF... Indicate the message used is cSPT_TIMED                 */
/* : : : : : [ENDIF]                                                          */
/* : : : : [ENDIF]                                                            */
/* : : : [ELSE]                                                               */
/* : : : : DE.... Compact the text according to just its length               */
/* : : : [ENDIF]                                                              */
/* : : : [IF there is no message]                                             */
/* : : : : DF.... Indicate the text is completely compacted,                  */
/* : : : [ENDIF]                                                              */
/* : : : [IF there is no message]                                             */
/* : : : : DG.... Indicate that there is no text, but perhaps a message       */
/* : : : [ENDIF]                                                              */
/* : : : E..... Create the complete information message                       */
/* : : : [IF there is no message]                                             */
/* : : : : EA.... Add the cSPT_PERCENT message                                */
/* : : : [ELSE]                                                               */
/* : : : : EB.... Add the cSPT_TIMED message                                  */
/* : : : [ELSE]                                                               */
/* : : : : [IF the message is at least TIMED]                                 */
/* : : : : : EC.... Add the cSPT_PERCENT message                              */
/* : : : : [ELSE]                                                             */
/* : : : : : ED.... Add the cSPT_TIMED message                                */
/* : : : : [ENDIF]                                                            */
/* : : : [ENDIF]                                                              */
/* : : : EE.... Scrub the text to delete trailing characters                  */
/* : : : F..... Modify the progress bar size according of its size            */
/* : : : [IF there is no message]                                             */
/* : : : : FA.... Get the length of the complete text plus its margin         */
/* : : : [ENDIF]                                                              */
/* : : : [IF there is no message]                                             */
/* : : : : FB.... Get the maximum length of the text pane                     */
/* : : : [ENDIF]                                                              */
/* : : : FC.... Set the new progress bar rectangle                            */
/* : : : FD.... Move the left side of the progress bar after the text         */
/* : : : FE.... Move the right side of the text to the beginning of the bar   */
/* : : [ENDIF]                                                                */
/* : : FF.... Make sure the previous text is erased                           */
/* : [ENDIF]                                                                  */
/* : G..... Refresh the progress bar                                          */
/* : [IF the progress bar is visible]                                         */
/* : : [IF text is visble]                                                    */
/* : : : GA.... Move the progress bar                                         */
/* : : [ELSE]                                                                 */
/* : : : [IF there is no message]                                             */
/* : : : : GB.... Display the modified progress bar                           */
/* : : : [ENDIF]                                                              */
/* : : [ENDIF]                                                                */
/* : [ENDIF]                                                                  */
/* : H..... Display the complete information message                          */
/* : [IF the progress bar is visible]                                         */
/* : : [IF text is visble]                                                    */
/* : : : [IF there is no message]                                             */
/* : : : : HA.... Text in pane 0 of the status bar                            */
/* : : : [ELSE]                                                               */
/* : : : : HB.... Text in the CWnd text pane                                  */
/* : : : [ENDIF]                                                              */
/* : : [ENDIF]                                                                */
/* : [ENDIF]                                                                  */
/* [ENDIF]                                                                    */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
#define cRTP_BLOCK   (           1 << 0)
#define cRTP_NOTEXT  (cRTP_BLOCK   << 1)
#define cRTP_PERCENT (cRTP_NOTEXT  << 1)
#define cRTP_TIMED   (cRTP_PERCENT << 1)
BOOL CSkinProgress::RefreshPanes
(
) 
{ // Resize the text pane and the progress bar
  CStatusBar* l_poStatusBar;
  CWnd*       l_poTextCWnd;
  CFont*      l_poFontOld;

  CString     l_oStrMessage;    // Working buffer for mp_oStrMessage
  CString     l_oStrPercent;    // Percent of completion level
  CString     l_oStrTimed;      // Timed completion level

  int         l_nProgressText;  // Absolute value of <mp_nProgressText>

  int         l_nLenMessage;    // Len of mp_oStrMessage in pixel
  int         l_nLenPercent;    // Len of l_oStrPercent in pixel
  int         l_nLenTimed;      // Len of l_oStrTimed in pixel
  int         l_nLenMargin;     // Len of 2*' ' in pixel
  int         l_nLenCompact;    // Number of character packed

  int         l_nLenText;       // Allowed len of the text (used to wrap it)
  int         l_nLenPane;       // 
  int         l_nLenBlock;      // Flags for computation (text wrapping)

  CRect       l_oRectText;      // Rect of pane 0 -> l_oRectPane at the end of the process if mp_nPane == 0
  CRect       l_oRectPane;      // Rect of pane mp_nPane, can be also pane 0

  // Init

  l_poStatusBar = NULL; // AVOID /W4 -> HA.... *STUPID COMPILER*
  l_poTextCWnd  = NULL; // AVOID /W4 -> BA.... *STUPID COMPILER*

  l_nLenPercent = 0;    // AVOID /W4 -> DB.... *STUPID COMPILER*
  l_nLenTimed   = 0;    // AVOID /W4 -> DDA... *STUPID COMPILER*
  l_nLenText    = 0;    // AVOID /W4 -> DE.... *STUPID COMPILER*
  l_nLenBlock   = 0;    // AVOID /W4 -> F..... *STUPID COMPILER*

  if(mp_nProgressText < 0)
  {
    l_nProgressText = 0 - mp_nProgressText; // Make it positive
  }
  else
  {
    l_nProgressText = mp_nProgressText;
  }

  // Process + Return

  if(IsWindow(GetSafeHwnd()))
  {
// A..... Get the text pane pointer and dimension
#ifdef dCSP_DIALOG_PROGRESS
    if(mp_poWndProgress != NULL)
    {
// AA.... Dialog CWnd text anchor
      if(mp_poWndMessage != NULL)
      {
        l_poTextCWnd = mp_poWndMessage;
        l_poTextCWnd->GetWindowRect(l_oRectText);
      }else{}
    }
    else
    {
#endif // dCSP_DIALOG_PROGRESS
      l_poStatusBar = _GetStatusBar();
      if(l_poStatusBar != NULL)
      {
// AB.... Status bar pane 0
        l_poTextCWnd = l_poStatusBar;
        l_poStatusBar->GetItemRect(0, l_oRectText);
      }
      else
      {
        return FALSE;
      }
#ifdef dCSP_DIALOG_PROGRESS
    }
#endif // dCSP_DIALOG_PROGRESS

// B..... Progress pane size calculation
    if(_GetTargetRect(&l_oRectPane))
    {
// BA.... Set the size of the progress bar to the full width of its current pane
      l_nLenPane = l_oRectPane.Width();

      if(l_poTextCWnd != NULL)
      {
// BB.... Get text pane's DC
        CClientDC l_oDC(l_poTextCWnd);

        l_poFontOld = l_oDC.SelectObject(l_poTextCWnd->GetFont());

#ifdef dCSP_DIALOG_PROGRESS
        if(mp_poWndProgress == NULL)
        {
#endif // dCSP_DIALOG_PROGRESS
// BC.... Calculate the fixed size of the progress bar
          if
          (
               (mp_nPane == 0)
            && (mp_nSize != 0)
          )
          { // If the text pane is shared with the progress bar, calculate how much space the text takes up
            if(mp_nSize > 0)
            { // Force progress bar size
// BCA... Calculate the remaining size for the text once removed the fixed size of the progress bar
              l_nLenPane = l_oRectText.Width() - (mp_nSize - 3); // Minus 3 to keep the same spacing with the others ways just below, to resize the text
              l_nLenText = l_nLenPane; // Use the remaining space left by the resized progress bar
            }
            else
            { // Resize the progress bar if the text is too long
// BCB... Calculate the size of the text to use (here the whole width of pane 0)
              l_nLenPane = l_oRectText.Width() + mp_nSize; // *BEWARE* : mp_nSize < 0 -> Get the optimal width of the progress bar before resizing it if necessary
              l_nLenText = l_oRectText.Width() - 3; // Use the whole space of pane 0, minus 3 to avoid a complete pane 0 disclosure leading to a windows bug
            }
          }
          else
          { // Resize the text if it is too long (even in pane 0 if mp_nSize == 0)
// BCC... Use whole width of pane 0 for the text, and what remains for the progress bar
            l_nLenPane = 0; // Full length for the progress bar, might be resized for pane 0
            l_nLenText = l_oRectText.Width() - 3; // Use the whole space of pane 0, minus 3 to avoid a complete pane 0 disclosure leading to a windows bug
          }
#ifdef dCSP_DIALOG_PROGRESS
        }
        else
        {
// BD.... Use all the space of the CWnd text anchor
          if(l_poTextCWnd != NULL)
          { // Use the whole lenght of the CWnd text pane
            l_nLenText = l_oRectText.Width();
          }else{}
        }
#endif // dCSP_DIALOG_PROGRESS

        if(l_poTextCWnd->IsWindowVisible())
        { // Redraw the text window
// C..... Get optional message length
          if(l_nProgressText != cSPT_NONE)
          { // Calculate progress text
// CA.... Get the length of the cSPT_PERCENT message
            l_oStrPercent.Format
            ( "%d%%"
            , (int) // Result on 'int'
              ( // From 0 to 100
                ( (LONGLONG) // Turns the whole calculation in 64 bits
                  (mp_nRight - mp_nLower)
                * 100
                )
                / (mp_nUpper - mp_nLower)
              )
            );

            if(mp_nProgressText > 0)
            {
              l_oStrPercent = "(" + l_oStrPercent + ")";
            }else{}

            l_oStrPercent = " " + l_oStrPercent;
            l_nLenPercent = l_oDC.GetTextExtent(l_oStrPercent).cx; // Length of Percent

            if(l_nProgressText >= cSPT_TIMED)
            {
// CB.... Get the length of the cSPT_TIMED message
              _GetTimed(&l_oStrTimed);
              l_nLenTimed = l_oDC.GetTextExtent(l_oStrTimed).cx; // Length of Timed
            }else{}
          }else{}

// CC.... Get the length of the text to display
          l_oStrMessage = mp_oStrMessage;
          l_nLenMessage = l_oDC.GetTextExtent(l_oStrMessage).cx; // Length of Message
          l_nLenMargin  = l_oDC.GetTextExtent(" ").cx << 1; // Text margin

// D..... Compact the text in the remaining space
          // Dompact the text
          switch(l_nProgressText)
          {
            case cSPT_NONE :
// DA.... Compact the text according to just its length
              l_nLenCompact = _CompactText(&l_oStrMessage, &l_oDC, l_nLenText, l_nLenMargin);
              break;
            case cSPT_PERCENT :
// DB.... Compact the text according to its length minus the length of the cSPT_PERCENT message
              l_nLenCompact = _CompactText(&l_oStrMessage, &l_oDC, l_nLenText, l_nLenMargin + l_nLenPercent);
              break;
            case cSPT_TIMED :
// DC.... Compact the text according to its length minus the length of the cSPT_TIMED message
              l_nLenCompact = _CompactText(&l_oStrMessage, &l_oDC, l_nLenText, l_nLenMargin + l_nLenTimed);
              break;
            case cSPT_AUTOSIZE :
// DD.... Compact the text according to the most usable remaining place between the text and the progress bar
// DDA... Try to compact the text with the cSPT_TIMED message at first
              l_nLenCompact = _CompactText(&l_oStrMessage, &l_oDC, l_nLenText, l_nLenMargin + l_nLenTimed);
              if
              (
                   (l_nLenCompact != 0)
                && (l_nLenCompact != l_oStrMessage.GetLength())
              )
              { // If the message was compacted, try with Percent
// DDB... Reset the text
                l_oStrMessage = mp_oStrMessage; // Restore the message

// DDC... Calculate the length of the three dots that will be displayed after the cSPT_PERCENT message
                // In case of Timed wrapping, use Percent instead, but add "..." to show that the Timed information was wrapped
                l_oStrPercent += "...";
                l_nLenPercent = l_oDC.GetTextExtent(l_oStrPercent).cx; // Length of Percent

// DDD... Compact the text according to its length minus the length of the cSPT_PERCENT message and the added three dots
                // Dompact the Percent + "..." information
                l_nLenCompact = _CompactText(&l_oStrMessage, &l_oDC, l_nLenText, l_nLenMargin + l_nLenPercent);
// DDE... Indicate the message used is cRTP_PERCENT
                l_nLenBlock |= cRTP_PERCENT;
              }
              else
              { // There was enough place to add the Timed information
// DDF... Indicate the message used is cSPT_TIMED
                l_nLenBlock |= cRTP_TIMED;
              }
              break;
            default :
// DE.... Compact the text according to just its length
              l_nLenCompact = _CompactText(&l_oStrMessage, &l_oDC, l_nLenText, l_nLenMargin);
              break;
          }

#ifdef dCSP_DIALOG_PROGRESS
          if(mp_poWndProgress == NULL)
          {
#endif // dCSP_DIALOG_PROGRESS
            // Block the text wrapping if there is nothing more to wrap
            if
            (
                 (l_nLenCompact < 0)
              || (
                      (l_oStrMessage.GetLength() <= 4)
                   && (l_oStrMessage.Right(3) == "...")
                 )
            )
            {
// DF.... Indicate the text is completely compacted, 
              l_nLenBlock |= cRTP_BLOCK;
            }else{}

            if(l_oStrMessage == "")
            {
// DG.... Indicate that there is no text, but there might be a message
              l_nLenBlock |= cRTP_NOTEXT;
            }else{}
#ifdef dCSP_DIALOG_PROGRESS
          }else{}
#endif // dCSP_DIALOG_PROGRESS

// E..... Create the complete information message with the user text and the completion report
          // Add the information
          switch(l_nProgressText)
          {
            case cSPT_NONE :
              break;
            case cSPT_PERCENT :
// EA.... Add the cSPT_PERCENT message
              l_oStrMessage += l_oStrPercent;
              break;
            case cSPT_TIMED :
// EB.... Add the cSPT_TIMED message
              l_oStrMessage += l_oStrTimed;
              break;
            case cSPT_AUTOSIZE :
              if((l_nLenBlock & cRTP_PERCENT) != 0)
              { // If the message was compacted, try with Percent
// EC.... Add the cSPT_PERCENT message
                l_oStrMessage += l_oStrPercent;
              }
              else
              { // There was enough place to add the Timed information
// ED.... Add the cSPT_TIMED message
                l_oStrMessage += l_oStrTimed;
              }
              break;
            default :
              break;
          }

// EE.... Scrub the text to delete trailing characters
          l_oStrMessage.TrimLeft();

#ifdef dCSP_DIALOG_PROGRESS
          if(mp_poWndProgress == NULL)
          {
#endif // dCSP_DIALOG_PROGRESS
// F..... Modify the progress bar size according of its size
            if(mp_nPane == 0)
            { // If the text pane is shared with the progress bar, calculate how much space the text takes up to
              l_nLenMessage = l_oDC.GetTextExtent(l_oStrMessage).cx; // Length of the compacted Message

              if
              (
                   (
                        (
                            (l_nLenMessage + l_nLenMargin) // Lenght of Message + Margin
                          > (l_nLenPane)                 // Lenght of remaining space for text
                        )
                     && (
                             (mp_nSize <= 0) // Resize of the progress bar if the text is longer, also used for mp_nSize == 0
                          || (
                                  (l_nLenMessage > 0)
                               && ((l_nLenBlock & cRTP_NOTEXT) != 0)
                             )
                        )
                   )
                || ((l_nLenBlock & cRTP_BLOCK) != 0) // Avoid paning if the text is wrapped to the max (when only "...'+information remains)
              )
              { // *IF* the packed text is larger than the space left by the resized progress bar *AND* the resizing of the progress bar is allowed *OR* the wrapping is blocked
// FA.... Get the length of the complete text plus its margin
                l_nLenPane = l_nLenMessage;

                if(l_nLenMessage > 0)
                {
                  l_nLenPane += l_nLenMargin;
                }else{}
              }else{}

              if(l_nLenPane > l_oRectText.Width())
              { // Make sure the length will stay positive
// FB.... Get the maximum length of the text pane
                l_nLenPane = l_oRectText.Width();
              }else{}

              if(l_nLenPane < 2)
              {
                l_nLenPane = 2;
              }else{}

// FC.... Set the new progress bar rectangle
              // This is the pane to display
              l_oRectPane = l_oRectText;

// FD.... Move the left side of the progress bar to the right of the text
              // Move left edge of the progress bar to the right, to leave some place for the text
              l_oRectPane.left = l_nLenPane;

// FE.... Move the right side of the text to the beginning of the bar
              l_oRectText.right = l_nLenPane;
            }else{}
#ifdef dCSP_DIALOG_PROGRESS
          }else{}
#endif // dCSP_DIALOG_PROGRESS
        }else{}

// FF.... Make sure the previous text is erased, so display at least a space character
        if(l_oStrMessage == "")
        {
          l_oStrMessage = " "; // If no text, force the pane to be cleared
        }else{}

        // Release DC
        l_oDC.SelectObject(l_poFontOld);
      }else{}

      if(IsWindowVisible())
      {
// G..... Refresh the progress bar
        if
        (
             (mp_oRectPane != l_oRectPane)
          && ( // Avoid pane disclosure, so that you can reopen the window and the pane won't stay closed
                  (l_oRectPane.Width()  > 2)
               && (l_oRectPane.Height() > 2)
             )
        )
        {
// GA.... Move the progress bar
          mp_oRectPane = l_oRectPane; // The new progress rectangle
          MoveWindow(&l_oRectPane);
          Invalidate(); // Display the progress bar on its new position
        }
        else
        {
          if(_UpdateProgress())
          {
// GB.... Display the modified progress bar
            Invalidate(); // Display the changes
          }else{}
        }
      }else{}

      if(l_poTextCWnd != NULL)
      {
        if(mp_oStrPrevMessage != l_oStrMessage)
        { // If the new message has changed from the previous, set it
// H..... Display the complete information message
#ifdef dCSP_DIALOG_PROGRESS
          if(mp_poWndProgress == NULL)
          {
#endif // dCSP_DIALOG_PROGRESS
// HA.... Text in pane 0 of the status bar
            l_poStatusBar->SetPaneText(0, l_oStrMessage); // Force text in pane 0
            mp_oStrPrevMessage = l_oStrMessage;
#ifdef dCSP_DIALOG_PROGRESS
          }
          else
          {
            if(mp_poWndMessage != NULL)
            {
// HB.... Text in the CWnd text pane
              mp_poWndMessage->SetWindowText(l_oStrMessage);
              mp_oStrPrevMessage = l_oStrMessage;
            }else{}
          }
#endif // dCSP_DIALOG_PROGRESS
        }else{}
      }else{}

      return TRUE;
    }
    else
    {
      return FALSE;
    }
  }
  else
  {
    return FALSE;
  }
}

// *** DATA PROCESS ***

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : _CompactText                                               */
/* Role          : None                                                       */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   int : > 0 = Number of character packed                   */
/*                           0 = Nothing packed                               */
/*                         < 0 = Pack blocked                                 */
/*                 OUTPUT (pointer to value)                                  */
/*                   io_poString  : Packed and three-doted text               */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   io_poString  : Text to compact                           */
/*                   i_poDC       : Target DC                                 */
/*                   i_nMaxWidth  : Width in pixel the text should fits in    */
/*                   i_nAddWidth  : Additional width for some purposes        */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Get the current DC                                     */
/*                 B - Remove any ending dots                                 */
/*                 C - Verify there is something to do                        */
/*                 D - Check if the text can be compacted                     */
/*                 E - Compact the string                                     */
/*                 F - Add the three dots at the end of the string            */
/*----------------------------------------------------------------------------*/
/* PROC _CompactText                                                          */
/*                                                                            */
/* [IF a string is provided to process]                                       */
/* : [IF no DC specified]                                                     */
/* : : A..... Get the current DC                                              */
/* : [ENDIF]                                                                  */
/* : [IF there is ending dots]                                                */
/* : : B..... Remove any ending dots                                          */
/* : [ENDIF]                                                                  */
/* : C..... Verify there is something to do                                   */
/* : [IF something have to be done]                                           */
/* : : D..... Check if the text can be compacted                              */
/* : : [IF the text can be compacted]                                         */
/* : : : E..... Compact the string as long as it does'nt fit                  */
/* : : : D..... Add the three dots at the end of the string                   */
/* : : [ENDIF]                                                                */
/* : [ENDIF]                                                                  */
/* [ENDIF]                                                                    */
/*----------------------------------------------------------------------------*/
/* Quite easy and fun to use... No trailing blank characters !                */
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CSkinProgress::_CompactText
( CString* io_poString
, CDC*     i_poDC
, int      i_nMaxWidth
, int      i_nAddWidth
)
{
  int     l_nLenString;
  int     l_nLenDots;
  int     l_nCountChar;
  TCHAR   l_nFirstChar;
  
  // Init

  if(io_poString != NULL)
  {
    if(i_poDC == NULL)
    { // If no target device context provided, use the current one
// A..... Get the current DC
      CClientDC l_oDC(this);
      i_poDC = &l_oDC;
    }else{}

    l_nLenString = io_poString->GetLength();
    if(io_poString->Right(3) == "...")
    {
// B..... Remove any ending dots
      l_nLenString -= 3;
      *io_poString  = io_poString->Left(l_nLenString);
    }else{}

  // Process + Return

// C..... Verify there is something to do
    if
    (
         (l_nLenString == 0) // No text
      || ( // Enough space for the unmodified text and the margin
              (i_poDC->GetTextExtent(*io_poString, l_nLenString).cx + i_nAddWidth)
           <= i_nMaxWidth
         )
    )
    {
      return 0;
    }
    else
    {
// D..... Check if the three doted first character is longer than the whole string (VERY few characters only)
      l_nFirstChar = io_poString->GetAt(0);
      l_nLenDots   = i_poDC->GetTextExtent(g_anThreeDots, sizeof(g_anThreeDots)).cx;
      if
      (
           i_poDC->GetTextExtent(*io_poString, l_nLenString).cx
        <= (i_poDC->GetTextExtent(&l_nFirstChar, sizeof(l_nFirstChar)).cx + l_nLenDots)
      )
      {
        return (0 - l_nLenString);
      }
      else
      {
        l_nCountChar = 0; 
        
// E..... Compact the string as long as it does'nt fit in the desired space
        while
        ( // As long as something remains *AND* the stuff is bigger than the allowed space
             (l_nLenString > 1) // Leading character must remain at least
          && (
                 (
                     i_poDC->GetTextExtent
                     ( *io_poString
                     , l_nLenString
                     ).cx
                   + (l_nLenDots >> 1)
                   + i_nAddWidth
                 )
               > i_nMaxWidth
             )
        )
        {
          *io_poString = io_poString->Left(io_poString->GetLength() - 1); // BEWARE : Modify the original object
          io_poString->TrimRight();               // Kill spaces 
          l_nLenString  = io_poString->GetLength(); // Get the real length after trim
          l_nCountChar += 1;
        }

// F..... Add the three dots at the end of the string
        *io_poString += g_anThreeDots;

        return l_nCountChar;
      }
    }
  }
  else
  {
    return 0;
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : _GetTimed                                                  */
/* Role          : Get a complete and accurate timed text message             */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : NEVER                                     */
/*                          TRUE  : ALWAYS                                    */
/*                 OUTPUT (pointer to value)                                  */
/*                   o_poTimed : Timed message                                */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Get current date and time                              */
/*                 B - Add start date in timed message if necessary           */
/*                 C - Add start time int timed message                       */
/*                 D - Add the time elapsed from start                        */
/*                 E - Add the current progress completion status             */
/*                 F - Add the remaining progress completion                  */
/*                 G - Get the remaining time before end                      */
/*                 H - Display the expected date and time of the end          */
/*----------------------------------------------------------------------------*/
/* PROC _GetTimed                                                             */
/*                                                                            */
/* A..... Get current date and time                                           */
/* B..... Add start date in timed message if necessary                        */
/* C..... Add start time int timed message                                    */
/* D..... Add the time elapsed from start                                     */
/* E..... Add the current progress completion status                          */
/* F..... Add the remaining progress completion                               */
/* G..... Get the remaining time before end                                   */
/* H..... Display the expected date and time of the end                       */
/*----------------------------------------------------------------------------*/
/* I will in the next update recode a bit this mess because if the progress   */
/* is not linear, the end time is far from being accurate. You might see that */
/* when grabing the bottom-right corner of the main window to resize it. It   */
/* block the progress, but the timer continue to elapse, so the end time      */
/* grows fast. Then, once you release the corner, the progress restart, but   */
/* then the time to finish is quite short so the remaining time decrease very */
/* fast, instead to readapt to show a 1:1 linear timer till the end.          */
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CSkinProgress::_GetTimed
( CString* o_poTimed
)
{
  CString       l_oStrTempo;
  unsigned long l_nTempo;

  SYSTEMTIME    l_sCurrentTimeSystem;
  SYSTEMTIME    l_sTempoTimeSystem;
  FILETIME      l_sTempoTimeFile;
  LONGLONG      l_nTempoTimeLongLong;
  LONGLONG      l_nDeltaTimeLongLong;

  // Init

// A..... Get current date and time
//  GetSystemTime(&nCurrentTime);
  GetLocalTime(&l_sTempoTimeSystem);
  l_sCurrentTimeSystem = l_sTempoTimeSystem; // For the Date of End and Time of End
  SystemTimeToFileTime(&l_sTempoTimeSystem, &l_sTempoTimeFile);

  l_nTempoTimeLongLong
  = ( (LONGLONG) // Turns the whole calculation in 64 bits
      l_sTempoTimeFile.dwHighDateTime
      << 32
    )
  | l_sTempoTimeFile.dwLowDateTime
  ;

  // Process

  *o_poTimed = " ";
  if(mp_nProgressText > 0)
  {
    *o_poTimed += "(";
  }else{}

// B..... Add start date in timed message if necessary
  if
  ( // *IF* Date of Start is different from Current Date
       (l_sTempoTimeSystem.wDay   != mp_sStartTimeSystem.wDay)   // Check what change first, days
    || (l_sTempoTimeSystem.wMonth != mp_sStartTimeSystem.wMonth)
    || (l_sTempoTimeSystem.wYear  != mp_sStartTimeSystem.wYear)
  )
  { // Date of Start
    l_oStrTempo.Format
    ( "%04d/%02d/%02d/%02d "
    , mp_sStartTimeSystem.wYear
    , mp_sStartTimeSystem.wMonth
    , mp_sStartTimeSystem.wDay
    , mp_sStartTimeSystem.wDayOfWeek + 1
    );
    *o_poTimed += l_oStrTempo;
  }else{}

// C..... Add start time in timed message
  // Time of Start
  l_oStrTempo.Format
  ( "%02d:%02d:%02d - "
  , mp_sStartTimeSystem.wHour
  , mp_sStartTimeSystem.wMinute
  , mp_sStartTimeSystem.wSecond
  );
  *o_poTimed += l_oStrTempo;

// D..... Add the time elapsed from start
  // Calculate time from start
  l_nDeltaTimeLongLong = l_nTempoTimeLongLong - mp_nStartTimeLongLong;
  l_nTempoTimeLongLong = l_nDeltaTimeLongLong; // Keep l_nDeltaTimeLongLong safe

  l_sTempoTimeFile.dwLowDateTime  = (DWORD) l_nTempoTimeLongLong;
  l_sTempoTimeFile.dwHighDateTime = (DWORD) ((LONGLONG) l_nTempoTimeLongLong >> 32);

  FileTimeToSystemTime(&l_sTempoTimeFile, &l_sTempoTimeSystem);
  l_sTempoTimeSystem.wYear -= 1600; // Starts from 1601, so if 1601 you get year 1

  // Day from start
  if
  (
       (l_sTempoTimeSystem.wYear  != 1)
    || (l_sTempoTimeSystem.wMonth != 1)
    || (l_sTempoTimeSystem.wDay   != 1)
  )
  { // If not the same day, calculate the number of days elapsed from start
    l_nTempo
    = (unsigned long)
      (
          l_nTempoTimeLongLong // Already in 64 bits, so the calculation will be done in 64 bits
        / (l_nDeltaTimeLongLong / 864000000000) // Number of days given in 100 nanosecond (0.1us)
      )
    ;

    if(l_nTempo != 0)
    { // If there is some days elapsed
      l_oStrTempo.Format
      ( "%d:"
      , l_nTempo
      );
      *o_poTimed += l_oStrTempo;
    }else{}
  }else{}

  // Time from start
  l_oStrTempo.Format
  ( "%02d:%02d:%02d - "
  , l_sTempoTimeSystem.wHour
  , l_sTempoTimeSystem.wMinute
  , l_sTempoTimeSystem.wSecond
  );
  *o_poTimed += l_oStrTempo;

// E..... Add the current progress completion status
  // Elapsed percent
  l_nTempo
  = (int)
  ( // 100% *256 to keep a pseudo 8-bits fixed point value (0.00390625 - 1/256 - resolution)
    ( (LONGLONG) // Turns the whole calculation in 64 bits
#ifndef dCSP_SLIDERBAR_METHOD
      (mp_nRight - mp_nLower)
#else
      (mp_nRight -  mp_nLeft)
#endif // dCSP_SLIDERBAR_METHOD
      * 25600
    )
    / (mp_nUpper - mp_nLower)
  );

  l_oStrTempo.Format
  ( "%d%% / "
  , l_nTempo >> 8 // '>> 8' == '/ 256'
  );
  *o_poTimed += l_oStrTempo;

// F..... Add the remaining progress completion
  // Remaining percent
  l_oStrTempo.Format
  ( "%d%% - "
  , 100 - (l_nTempo >> 8)
  );
  *o_poTimed += l_oStrTempo;

// G..... Get the remaining time before end
  // Remaining time
  if(l_nTempo == 0)
  { // Avoid zero divide
    l_nTempoTimeLongLong = 0; // No more time to wait
  }
  else
  {
    l_nTempoTimeLongLong
    = (
          (l_nDeltaTimeLongLong * 25600)
        / l_nTempo
      )
    - l_nDeltaTimeLongLong
    ; // The remaining time, 100% - Elasped (100% = Elapsed / Percent)
  }

  l_sTempoTimeFile.dwLowDateTime  = (DWORD) l_nTempoTimeLongLong;
  l_sTempoTimeFile.dwHighDateTime = (DWORD) ((LONGLONG) l_nTempoTimeLongLong >> 32);

  FileTimeToSystemTime(&l_sTempoTimeFile, &l_sTempoTimeSystem);
  l_sTempoTimeSystem.wYear       -= 1600;

  // Day to end
  if
  (
       (l_sTempoTimeSystem.wDay   != 1) // Check what change first, days
    || (l_sTempoTimeSystem.wMonth != 1)
    || (l_sTempoTimeSystem.wYear  != 1)
  )
  { // If not the same day, calculate the number of days elapsed from start
    l_nTempo
    = (unsigned long)
      (
          l_nDeltaTimeLongLong
        / 864000000000 // Number of days given in 100 nanosecond (0.1us)
      )
    ;

    if(l_nTempo != 0)
    { // If there is some days elapsed
      l_oStrTempo.Format("%d:", l_nTempo);
      *o_poTimed += l_oStrTempo;
    }else{}
  }else{}

  // Time to end
  l_oStrTempo.Format
  ( "%02d:%02d:%02d - "
  , l_sTempoTimeSystem.wHour
  , l_sTempoTimeSystem.wMinute
  , l_sTempoTimeSystem.wSecond
  );
  
  *o_poTimed += l_oStrTempo;

// H..... Display the expected date and time of the end
  // Date of End
  if(l_nTempo == 0)
  { // Avoid zero divide
    l_nTempoTimeLongLong = mp_nStartTimeLongLong + l_nDeltaTimeLongLong; // Current time, Delta = Tempo - Start, see above
  }
  else
  {
    l_nTempoTimeLongLong = mp_nStartTimeLongLong + ((l_nDeltaTimeLongLong * 25600) / l_nTempo); // Start + 100% (100% = Elapsed / Percent)
  }

  l_sTempoTimeFile.dwLowDateTime  = (DWORD) l_nTempoTimeLongLong;
  l_sTempoTimeFile.dwHighDateTime = (DWORD) ((LONGLONG) l_nTempoTimeLongLong >> 32);
  FileTimeToSystemTime(&l_sTempoTimeFile, &l_sTempoTimeSystem);

  if
  (
       (l_sTempoTimeSystem.wYear  != l_sCurrentTimeSystem.wYear)
    && (l_sTempoTimeSystem.wMonth != l_sCurrentTimeSystem.wMonth)
    && (l_sTempoTimeSystem.wDay   != l_sCurrentTimeSystem.wDay)
  )
  {
    l_oStrTempo.Format
    ( "%04d/%02d/%02d/%02d "
    , l_sTempoTimeSystem.wYear
    , l_sTempoTimeSystem.wMonth
    , l_sTempoTimeSystem.wDay
    , l_sTempoTimeSystem.wDayOfWeek + 1
    );

    *o_poTimed += l_oStrTempo;
  }else{}

  // Time of End
  l_oStrTempo.Format
  ( "%02d:%02d:%02d"
  , l_sTempoTimeSystem.wHour
  , l_sTempoTimeSystem.wMinute
  , l_sTempoTimeSystem.wSecond
  );

  *o_poTimed += l_oStrTempo;

  if(mp_nProgressText > 0)
  {
    *o_poTimed += ")";
  }else{}

  // Return

  return TRUE;
}

// *** UPDATE PROCESS ***

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : _UpdateProgress                                            */
/* Role          : None                                                       */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   BOOL = FALSE : The progress bar has not changed          */
/*                          TRUE  : The display needs to be updated           */
/*                 OUTPUT (pointer to value)                                  */
/*                   o_poRectPaint : Return the progress bar client rect      */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Get the current progress bar dimension                 */
/*                 B - Set variables for calculation                          */
/*                 C - Calculate the elements' position in pixel              */
/*                 D - Reverse the left and right element position            */
/*                 E - On progress bar change, return the need to refresh it  */
/*----------------------------------------------------------------------------*/
/* PROC _UpdateProgress                                                       */
/*                                                                            */
/* A..... Get the current progress bar dimension                              */
/* B..... Set variables for calculation                                       */
/* C..... Calculate the elements' position                                    */
/*   CA.... Get the position of the end of the progress bar                   */
/*   CB.... Get the length in pixel of the prgress bar                        */
/*   CC.... Get the position of the left end of the progress bar              */
/*   [IF the lenght of the progress bar exceed the end position]              */
/*   : CD... Reset the length of the progress bar to its maximum size         */
/*   [ENDIF]                                                                  */
/*   [IF the left element is located after the right element]                 */
/*   : CE... Set the start before the end                                     */
/*   [ENDIF]                                                                  */
/* [IF the display is reversed]                                               */
/* : D..... Reverse the left and right elements position                      */
/* [ENDIF]                                                                    */
/* E..... On progress bar change, return the need to refresh it               */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CSkinProgress::_UpdateProgress
( CRect* o_poRectPaint // = NULL
) 
{ // Update of the progress bar values
  CRect l_oRectPaint;
#ifdef dCSP_SLIDERBAR_METHOD
  int   l_nCurrentPos; // Pos of the current calculated position
#endif // dCSP_SLIDERBAR_METHOD
  int   l_nLenPos;
  int   l_nStepPos;

  // Init

  // Init

// A..... Get the current progress bar dimension
  GetClientRect(&l_oRectPaint); // the CStatic currently being repaint
  if(o_poRectPaint != NULL)
  {
    *o_poRectPaint = l_oRectPaint;
  }else{}
//  GetParent()->GetClientRect(&rcStatusBar); // For old test purpose, just stay here to recall me the syntax
//  GetParent()->ClientToScreen(&rcStatusBar);
//  ScreenToClient(&rcStatusBar);

// B...... Set variables for calculation
#ifdef dCSP_VERTICAL_BAR
  if(mp_bVertical == TRUE)
  { // Vertical bar
    l_nLenPos  = l_oRectPaint.Height();
    l_nStepPos = mp_nBmpHeight;
  }
  else
#endif // dCSP_VERTICAL_BAR
  { // Horizontal bar
    l_nLenPos  = l_oRectPaint.Width();
    l_nStepPos = mp_nBmpWidth;
  }

  // Process

  // mp_nEndAff ---------------------------------------------------,
  // mp_nRightAff ----------------------------,                    |
  // mp_nLeftAff ---------,                   | mp_nBmpWidth --,-, |
  //                      |<------ bar ------>|                | | |
  // ProgressBar = [ : : :(:=:=:=:=:=:=:=:=:=:): : : : : : : : : : : ]
  //               | |                                           | |
  //               | '- 0% --------- mp_nRightAff -------- 100% -+-'
  //               '- 0% --------- mp_nLeftAff ----------- 100% -'

// C..... Calculate the elements' position in pixel
// CA.... Get the position of the end of the progress bar
  mp_nEndAff = l_nLenPos - l_nStepPos; // Position of the cSPB_RIGHT element

// CB.... Get the position of the right end of the progress bar
  mp_nRightAff
  = (int)
    ( // Position of the cSPB_RIGHT element
      ( (LONGLONG) // Turns the whole calculation in 64 bits
        (mp_nRight - mp_nLower)
        * (l_nLenPos  - (l_nStepPos << 1))
      )
      / (mp_nUpper - mp_nLower)
    )
  + l_nStepPos
  ;

#ifdef dCSP_SLIDERBAR_METHOD
// CC.... Get the position of the left end of the progress bar
  mp_nLeftAff
  = (int)
    ( // Position of the cSPB_LEFT element
      ( (LONGLONG) // Turns the whole calculation in 64 bits
        (mp_nLeft - mp_nLower)
        * (l_nLenPos - (l_nStepPos << 1)) 
      )
      / (mp_nUpper - mp_nLower)
    )
  ;
#endif // dCSP_SLIDERBAR_METHOD

  if(mp_nRightAff > mp_nEndAff)
  { // Cannot be be bigger than the bar itselves
// CD.... Reset the length of the progress bar to its maximum size
    mp_nRightAff = mp_nEndAff;
  }else{}

#ifdef dCSP_SLIDERBAR_METHOD
  if(mp_nLeftAff > (mp_nRightAff - l_nStepPos))
  { // Cannot be be bigger than the bar itselves
// CE.... Set the start before the end
    mp_nLeftAff = mp_nRightAff - l_nStepPos;
  }else{}
#endif // dCSP_SLIDERBAR_METHOD

// D..... Reverse the left and right elements position
#ifdef dCSP_SLIDERBAR_METHOD
  if(mp_bReverse != FALSE)
  { // If reversing the display, just invert the positions in dCSP_SLIDERBAR_METHOD mode, TRICKY ISN'T IT !
    l_nCurrentPos = l_nLenPos - mp_nRightAff - l_nStepPos; // Will become mp_nLeftAff
    mp_nRightAff  = l_nLenPos - mp_nLeftAff  - l_nStepPos; // mp_nLeftAff  becomes mp_nRightAff
    mp_nLeftAff   = l_nCurrentPos;                         // mp_nRightAff becomes mp_nLeftAff
  }else{}
#endif // dCSP_SLIDERBAR_METHOD

  // Return

// E..... On progress bar change, return the need to refresh it
  if
  (
       (mp_nPrevEndAff   != mp_nEndAff)
    || (mp_nPrevRightAff != mp_nRightAff)
#ifdef dCSP_SLIDERBAR_METHOD
    || (mp_nPrevLeftAff  != mp_nLeftAff)
#endif // dCSP_SLIDERBAR_METHOD
  )
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

// *** WINDOWS MAPPED PROCESSING ***

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : OnEraseBkgnd                                               */
/* Role          : Erase the background (with a filled rect) before [OnPaint] */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   i_poDC : current DC                                      */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Erase the background                                   */
/*                 B - Resize and display the text                            */
/*----------------------------------------------------------------------------*/
/* PROC OnEraseBkgnd                                                          */
/*                                                                            */
/* A..... Erase the background                                                */
/* B..... Resize and display the text                                         */
/*----------------------------------------------------------------------------*/
/* This function is called prior to [OnSizing] because we cannot over-ride    */
/* the status bar [OnSizing] function from here. And we also cannot do it for */
/* the main window also, which is the parent window of the status bar. So, in */
/* order to resize the text in real-time while it is moved/resized, just call */
/* the [RefreshPanes] function when the status bar is asked to be erased.     */
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CSkinProgress::OnEraseBkgnd
( CDC* i_poDC
)
{
  BOOL l_bResult;

  // Init

// A..... Erase the background
  l_bResult = CStatic::OnEraseBkgnd(i_poDC);

  // Process

// B..... Resize and display the text
  RefreshPanes();

  // Return

  return l_bResult;
}

BEGIN_MESSAGE_MAP(CSkinProgress, CStatic)
	//{{AFX_MSG_MAP(CSkinProgress)
  ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinProgress message handlers

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : OnPaint                                                    */
/* Role          : Repaint the progress bar according to its new size         */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Update values, get dimension and check refresh         */
/*                 B - Set variables for calculation                          */
/*                 C - Draw the progress bar                                  */
/*                 D - Display the progress bar                               */
/*----------------------------------------------------------------------------*/
/* PROC OnPaint                                                               */
/*                                                                            */
/* A..... Update values, get dimension and check refresh                      */
/* [IF the progress bar needs to be refreshed]                                */
/* : B..... Set variables for calculation                                     */
/* : C..... Draw the progress bar                                             */
/* : [IF the progress bar size is different from the previous time]           */
/* : : CA.... Redraw the complete bar from scratch                            */
/* : : [IF the progress bar was existing]                                     */
/* : : : CAA... Delete the previous progress bar bitmap                       */
/* : : [ENDIF]                                                                */
/* : : CAB... Create the new progress bar bitmap with the new dimension       */
/* : [ENDIF]                                                                  */
/* : CB.... Select the DC on the progress bar bitmap                          */
/* : [IF the progress bar size is different from the previous time]           */
/* : : CC.... Start the complete redraw of the progress bar from the end      */
/* : :   CCA... Draw the background element                                   */
/* : :     CCAA.. Draw the background element at the most right position      */
/* : :     [UNTIL the right end of the progress bar is not reached]           */
/* : :     : CCAB.. Draw background element until the right end of the bar    */
/* : :     [NEXT]                                                             */
/* : :   CCB... Save the previous position of the end of the progress bar     */
/* : :   CCC... Draw the bar element                                          */
/* : :     CCCA.. Reset the drawing position on a base of an element's width  */
/* : :     [UNTIL the beginning is not reached]                               */
/* : :     : CCCB.. Draw the bar element until the left end of the bar        */
/* : :     [NEXT]                                                             */
/* : :   CCD... Draw the center element                                       */
/* : :   [IF not under the start element]                                     */
/* : :   : CCE... Draw the before-left element                                */
/* : :   [ENDIF]                                                              */
/* : :   [IF not under the end element]                                       */
/* : :   : CCF... Draw the after-right element                                */
/* : :   [ENDIF]                                                              */
/* : :   CCG... Draw the start element                                        */
/* : :   CCH... Draw the end element                                          */
/* : :   CCI... Draw the left element of the bar                              */
/* : :   CCJ... Draw the right element of the bar                             */
/* : [ELSE]                                                                   */
/* : : CD.... Modify the moved elements without redrawing everything          */
/* : :   CDA... Start to update the progress bar from the previous position   */
/* : :   [IF going backward (Oh my God, could it be possible ?)]              */
/* : :   : CDB... Going backward                                              */
/* : :   :   CDBA.. Draw background to replace the end of the progress bar    */
/* : :   :   CDBB.. Reset drawing position on a base of an element's width    */
/* : :   :   [UNTIL the right end of the progress bar is not reached]         */
/* : :   :   : CDBC.. Draw the background until the right end of the bar      */
/* : :   :   [NEXT]                                                           */
/* : :   [ELSE]                                                               */
/* : :   : CDC... Going forward                                               */
/* : :   :   CDCA.. Draw the bar element to replace the progress bar end      */
/* : :   :   CDCB.. Reset drawing position on a base of an element's width    */
/* : :   :   [UNTIL the right end of the progress bar is not reached]         */
/* : :   :   : CDCC.. Draw the progress bar until the right end of the bar    */
/* : :   :   [NEXT]                                                           */
/* : :   [ENDIF]                                                              */
/* : :   CDD... Draw the center element                                       */
/* : :   [IF moved AND not under the start element]                           */
/* : :   : CDE... Draw the before-left element                                */
/* : :   [ENDIF]                                                              */
/* : :   [IF moved AND not under the end element]                             */
/* : :   : CDF... Draw the after-right element                                */
/* : :   [ENDIF]                                                              */
/* : :   [IF modifed by BEFORE or LEFT or CENTER]                             */
/* : :   : CDG... Draw the start element                                      */
/* : :   [ENDIF]                                                              */
/* : :   [IF modifed by CENTER or RIGHT or AFTER]                             */
/* : :   : CDH... Draw the end element                                        */
/* : :   [ENDIF]                                                              */
/* : :   [IF LEFT moved OR RIGHT too close from LEFT]                         */
/* : :   : CDI... Draw the left element of the bar                            */
/* : :   [ENDIF]                                                              */
/* : :   [IF RIGHT moved OR LEFT too close from RIGHT]                        */
/* : :   : CDJ... Draw the right element of the bar                           */
/* : :   [ENDIF]                                                              */
/* : [ENDIF]                                                                  */
/* : D..... Display the progress bar                                          */
/* [ENDIF]                                                                    */
/*----------------------------------------------------------------------------*/
/* Specific details about the dCSP_SLIDERBAR_METHOD or the dCSP_VERTICAL_BAR  */
/* are not provided because beyon the scope of the class. The code is also    */
/* fully functionnal, but is not yet intented to be used. It will surely be   */
/* a near update. But right now, anyone who wants to understand how slider    */
/* bars and/or vertical bars works just have to understand first how the      */
/* progress bars works. Hope there is enough comments for this purpose ;p     */
/*--- END FUNCTION HEADER ----------------------------------------------------*/
void CSkinProgress::OnPaint
(
) 
{ // On redraw event
	CPaintDC l_oDC(this);   // Device context for painting - Do not call CStatic::OnPaint() for painting messages

  CDC      l_oDcProgress; // CompatibleDC
  CBitmap* l_poOldBitmap; // l_oDC's previous bitmap

  CRect    l_oRectPaint;
  int      l_nCurrentPos; // Pos of the current calculated position
  int      l_nStepPos;

//  LPPAINTSTRUCT sPaintStruct;

  // Init

  // Process

// A..... Update the progress bar elements position and get the progress bar dimension
  _UpdateProgress(&l_oRectPaint); // the CStatic currently being repaint

//  BeginPaint(sPaintStruct);

// B...... Set variables for calculation
#ifdef dCSP_VERTICAL_BAR
  if(mp_bVertical == TRUE)
  { // Vertical bar
    l_nStepPos = mp_nBmpHeight;
  }
  else
#endif // dCSP_VERTICAL_BAR
  { // Horizontal bar
    l_nStepPos = mp_nBmpWidth;
  }

// C..... Draw the progress bar
  if
  ( // If the SIZE (don't mind the position) of the ProgressBar has changed
       (l_oRectPaint.Width()  != mp_oRectPaint.Width())
    || (l_oRectPaint.Height() != mp_oRectPaint.Height())
  )
  { // If the progress bar size has changed
// CA.... Redraw the complete bar from scratch
    if(mp_poProgressBmp != NULL)
    { // If the ProgressBitmap already exists, delete it and create a new one with the new dimension of the pane
// CAA... Delete the previous progress bar bitmap
      delete mp_poProgressBmp;
    }else{}

// CAB... Create the new progress bar bitmap with the new dimension
    mp_poProgressBmp = new CBitmap;
    mp_poProgressBmp->CreateCompatibleBitmap
    ( &l_oDC // *ALWAYS* use '&l_oDC', *NEVER* '&l_oDcProgress' otherwise you'll get a monochrom image
    , l_oRectPaint.Width()
    , l_oRectPaint.Height()
    );
  }else{}

// CB.... Select the DC on the progress bar bitmap
  l_oDcProgress.CreateCompatibleDC(&l_oDC);
  l_poOldBitmap = l_oDcProgress.SelectObject(mp_poProgressBmp);

  if( // If the SIZE (don't mind the position) of the ProgressBar has changed
         (l_oRectPaint.Width()  != mp_oRectPaint.Width())
      || (l_oRectPaint.Height() != mp_oRectPaint.Height())
    )
  { // If the ProgressBar has changed, redraw it completly
// CC.... Start the complete redraw of the progress bar from the end
    // Background
// CCA... Draw the background element
// CCAA.. Draw the background element from the most right position
    for
    ( l_nCurrentPos = mp_nEndAff - (mp_nEndAff % l_nStepPos)
    ; l_nCurrentPos > mp_nRightAff
    ; l_nCurrentPos -= l_nStepPos
    )
    {
// CCAB.. Draw the background element until the right end of the bar
#ifdef dCSP_VERTICAL_BAR
      if(mp_bVertical == TRUE)
      { // Vertical bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_BACKGROUND
        , CPoint(0, l_nCurrentPos)
        , ILD_NORMAL
        );
      }
      else
#endif // dCSP_VERTICAL_BAR
      { // Horizontal bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_BACKGROUND
        , CPoint(l_nCurrentPos, 0)
        , ILD_NORMAL
        );
      }
    }

// CCB... Save the previous position of the end of the progress bar
    // Position of the end of the bar
    mp_nPrevRightAff = mp_nRightAff;

// CCC... Draw the bar element
    // Bar
// CCCA.. Reset the drawing position on a base of the image list element's width
    for
    ( l_nCurrentPos -= (l_nCurrentPos % l_nStepPos)
#ifndef dCSP_SLIDERBAR_METHOD
    ; l_nCurrentPos >= l_nStepPos // For mp_nLeft-less progress bar routine
#else
    ; l_nCurrentPos >= mp_nLeftAff
#endif // dCSP_SLIDERBAR_METHOD
    ;  l_nCurrentPos -= l_nStepPos
    )
    {
// CCCB.. Draw the bar element until the left end of the bar
#ifdef dCSP_VERTICAL_BAR
      if(mp_bVertical == TRUE)
      { // Vertical bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_BAR
        , CPoint(0, l_nCurrentPos)
        , ILD_NORMAL
        );
      }
      else
#endif // dCSP_VERTICAL_BAR
      { // Horizontal bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_BAR
        , CPoint(l_nCurrentPos, 0)
        , ILD_NORMAL
        );
      }
    }

#ifdef dCSP_SLIDERBAR_METHOD
    // Position of the beginning of the bar
    mp_nPrevLeftAff = mp_nLeftAff;

    // Background
    for
    ( l_nCurrentPos -= (l_nCurrentPos % l_nStepPos)
    ; l_nCurrentPos >= l_nStepPos
    ; l_nCurrentPos -= l_nStepPos
    )
    {
#ifdef dCSP_VERTICAL_BAR
      if(mp_bVertical == TRUE)
      { // Vertical bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_BACKGROUND
        , CPoint(0, l_nCurrentPos)
        , ILD_NORMAL
        );
      }
      else
#endif // dCSP_VERTICAL_BAR
      { // Horizontal bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_BACKGROUND
        , CPoint(l_nCurrentPos, 0)
        , ILD_NORMAL
        );
      }
    }
#endif // dCSP_SLIDERBAR_METHOD

// CCD... Draw the center element
    // Center
#ifdef dCSP_VERTICAL_BAR
    if(mp_bVertical == TRUE)
    { // Vertical bar
      mp_oBarImgLst.Draw
      ( &l_oDcProgress
      , cSPB_CENTER
#ifndef dCSP_SLIDERBAR_METHOD
      , CPoint(0, mp_nRightAff >> 1)
#else
      , CPoint(0, (mp_nLeftAff + mp_nRightAff) >> 1)
#endif // dCSP_SLIDERBAR_METHOD
      , ILD_NORMAL
      );
    }
    else
#endif // dCSP_VERTICAL_BAR
    { // Horizontal bar
      mp_oBarImgLst.Draw
      ( &l_oDcProgress
      , cSPB_CENTER
#ifndef dCSP_SLIDERBAR_METHOD
      , CPoint(mp_nRightAff >> 1, 0)
#else
      , CPoint((mp_nLeftAff + mp_nRightAff) >> 1, 0)
#endif // dCSP_SLIDERBAR_METHOD
      , ILD_NORMAL
      );
    }

// CCE... Draw the before-left element
    // Before
#ifdef dCSP_SLIDERBAR_METHOD
    if(mp_nLeftAff > l_nStepPos)
    {
#ifdef dCSP_VERTICAL_BAR
      if(mp_bVertical == TRUE)
      { // Vertical bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_BEFORE
        , CPoint(0, mp_nLeftAff - mp_nBmpHeight)
        , ILD_NORMAL
        );
      }
      else
#endif // dCSP_VERTICAL_BAR
      { // Horizontal bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_BEFORE
        , CPoint(mp_nLeftAff - mp_nBmpWidth, 0)
        , ILD_NORMAL
        );
      }
    }else{}
#endif // dCSP_SLIDERBAR_METHOD

// CCF... Draw the after-right element
    // After
    if(mp_nRightAff < (mp_nEndAff - l_nStepPos))
    {
#ifdef dCSP_VERTICAL_BAR
      if(mp_bVertical == TRUE)
      { // Vertical bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_AFTER
        , CPoint(0, mp_nRightAff + mp_nBmpHeight)
        , ILD_NORMAL
        );
      }
      else
#endif // dCSP_VERTICAL_BAR
      { // Horizontal bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_AFTER
        , CPoint(mp_nRightAff + mp_nBmpWidth, 0)
        , ILD_NORMAL
        );
      }
    }else{}

// CCG... Draw the start element
    // Start
#ifdef dCSP_SLIDERBAR_METHOD
    mp_oBarImgLst.Draw
    ( &l_oDcProgress
    , cSPB_START
    , CPoint(0, 0)
    , ILD_NORMAL
    );
#endif // dCSP_SLIDERBAR_METHOD

// CCH... Draw the end element
    // End
#ifdef dCSP_VERTICAL_BAR
    if(mp_bVertical == TRUE)
    { // Vertical bar
      mp_oBarImgLst.Draw
      ( &l_oDcProgress
      , cSPB_END
      , CPoint(0, mp_nEndAff)
      , ILD_NORMAL
      );
    }
    else
#endif // dCSP_VERTICAL_BAR
    { // Horizontal bar
      mp_oBarImgLst.Draw
      ( &l_oDcProgress
      , cSPB_END
      , CPoint(mp_nEndAff, 0)
      , ILD_NORMAL
      );
    }

// CCI... Draw the left element of the bar
    // Left
#ifdef dCSP_VERTICAL_BAR
    if(mp_bVertical == TRUE)
    { // Vertical bar
      mp_oBarImgLst.Draw // For mp_nLeft-less progress bar routine
      ( &l_oDcProgress
      , cSPB_TOP
#ifndef dCSP_SLIDERBAR_METHOD
      , CPoint(0, 0)
#else
      , CPoint(0, mp_nLeftAff)
#endif // dCSP_SLIDERBAR_METHOD
      , ILD_NORMAL
      );
    }
    else
#endif // dCSP_VERTICAL_BAR
    { // Horizontal bar
      mp_oBarImgLst.Draw // For mp_nLeft-less progress bar routine
      ( &l_oDcProgress
      , cSPB_LEFT
#ifndef dCSP_SLIDERBAR_METHOD
      , CPoint(0, 0)
#else
      , CPoint(mp_nLeftAff, 0)
#endif // dCSP_SLIDERBAR_METHOD
      , ILD_NORMAL
      );
    }

// CCJ// Car... Draw the right element of the bar
    // Right
#ifdef dCSP_VERTICAL_BAR
    if(mp_bVertical == TRUE)
    { // Vertical bar
      mp_oBarImgLst.Draw
      ( &l_oDcProgress
      , cSPB_BOTTOM
      , CPoint(0, mp_nRightAff)
      , ILD_NORMAL
      );
    }
    else
#endif // dCSP_VERTICAL_BAR
    { // Horizontal bar
      mp_oBarImgLst.Draw
      ( &l_oDcProgress
      , cSPB_RIGHT
      , CPoint(mp_nRightAff, 0)
      , ILD_NORMAL
      );
    }

    mp_nPrevEndAff = mp_nEndAff;
    mp_oRectPaint  = l_oRectPaint;
  }
  else
  {
// CD.... Modify the moved elements without redrawing the complete progress bar
    if(mp_nPrevRightAff != mp_nRightAff)
    {
// CDA... Start to update the progress bar from the previous position
      l_nCurrentPos = mp_nPrevRightAff;

      if(mp_nRightAff < mp_nPrevRightAff)
      { // If going backward, draw BACKGROUND and last with RIGHT
// CDB... Going backward
// CDBA.. Draw the background element to replace the end of the progress bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_BACKGROUND
        , CPoint(l_nCurrentPos, 0)
        , ILD_NORMAL
        );

// CDBB.. Reset the drawing position on a base of the image list element's width
        for
        ( l_nCurrentPos -= (l_nCurrentPos % l_nStepPos)
        ; l_nCurrentPos > mp_nRightAff
        ; l_nCurrentPos -= l_nStepPos
        )
        {
// CDBC.. Draw the background element until the right end of the bar
#ifdef dCSP_VERTICAL_BAR
          if(mp_bVertical == TRUE)
          { // Vertical bar
            mp_oBarImgLst.Draw
            ( &l_oDcProgress
            , cSPB_BACKGROUND
            , CPoint(0, l_nCurrentPos)
            , ILD_NORMAL
            );
          }
          else
#endif // dCSP_VERTICAL_BAR
          { // Horizontal bar
            mp_oBarImgLst.Draw
            ( &l_oDcProgress
            , cSPB_BACKGROUND
            , CPoint(l_nCurrentPos, 0)
            , ILD_NORMAL
            );
          }
        }
      }
      else
      { // If going forward, draw BAR and last with RIGHT
// CDC... Going forward
// CDCA.. Draw the progress bar element to replace the end of the progress bar
        mp_oBarImgLst.Draw(&l_oDcProgress, cSPB_BAR, CPoint(l_nCurrentPos, 0), ILD_NORMAL);
// CDCB.. Reset the drawing position on a base of the image list element's width
        
        l_nCurrentPos += l_nStepPos;

        for
        ( l_nCurrentPos -= (l_nCurrentPos % l_nStepPos)
        ; l_nCurrentPos  < mp_nRightAff
        ; l_nCurrentPos += l_nStepPos
        )
        {
// CDCC.. Draw the progress bar element until the right end of the bar
#ifdef dCSP_VERTICAL_BAR
          if(mp_bVertical == TRUE)
          { // Vertical bar
            mp_oBarImgLst.Draw
            ( &l_oDcProgress
            , cSPB_BAR
            , CPoint(0, l_nCurrentPos)
            , ILD_NORMAL
            );
          }
          else
#endif // dCSP_VERTICAL_BAR
          { // Horizontal bar
            mp_oBarImgLst.Draw
            ( &l_oDcProgress
            , cSPB_BAR
            , CPoint(l_nCurrentPos, 0)
            , ILD_NORMAL
            );
          }
        }
      }
    }else{}

#ifdef dCSP_SLIDERBAR_METHOD
    if(mp_nLeftAff!= mp_nPrevLeftAff)
    {
      l_nCurrentPos = mp_nPrevLeftAff;

      if(mp_nLeftAff < mp_nPrevLeftAff)
      { // If going backward, draw BAR and last with LEFT
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_BAR
        , CPoint(l_nCurrentPos, 0)
        , ILD_NORMAL
        );
        
        for
        ( l_nCurrentPos -= (l_nCurrentPos % l_nStepPos)
        ; l_nCurrentPos  > mp_nLeftAff
        ; l_nCurrentPos -= l_nStepPos
        )
        {
#ifdef dCSP_VERTICAL_BAR
          if(mp_bVertical == TRUE)
          { // Vertical bar
            mp_oBarImgLst.Draw
            ( &l_oDcProgress
            , cSPB_BAR
            , CPoint(0, l_nCurrentPos)
            , ILD_NORMAL
            );
          }
          else
#endif // dCSP_VERTICAL_BAR
          { // Horizontal bar
            mp_oBarImgLst.Draw
            ( &l_oDcProgress
            , cSPB_BAR
            , CPoint(l_nCurrentPos, 0)
            , ILD_NORMAL
            );
          }
        }
      }
      else
      { // If going forward, draw BACKGROUND and last with LEFT
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_BACKGROUND
        , CPoint(l_nCurrentPos, 0)
        , ILD_NORMAL
        );

        l_nCurrentPos += l_nStepPos;
        
        for
        ( l_nCurrentPos -= (l_nCurrentPos % l_nStepPos)
        ; l_nCurrentPos  < mp_nLeftAff
        ; l_nCurrentPos += l_nStepPos
        )
        {
#ifdef dCSP_VERTICAL_BAR
          if(mp_bVertical == TRUE)
          { // Vertical bar
            mp_oBarImgLst.Draw
            ( &l_oDcProgress
            , cSPB_BACKGROUND
            , CPoint(0, l_nCurrentPos)
            , ILD_NORMAL
            );
          }
          else
#endif // dCSP_VERTICAL_BAR
          { // Horizontal bar
            mp_oBarImgLst.Draw
            ( &l_oDcProgress
            , cSPB_BACKGROUND
            , CPoint(l_nCurrentPos, 0)
            , ILD_NORMAL
            );
          }
        }
      }
    }else{}
#endif // dCSP_SLIDERBAR_METHOD

// CDD... Draw the center element
    if(
           (mp_nPrevRightAff != mp_nRightAff)
#ifdef dCSP_SLIDERBAR_METHOD
        || (mp_nPrevLeftAff  != mp_nLeftAff)
#endif // dCSP_SLIDERBAR_METHOD
      )
    {
#ifdef dCSP_VERTICAL_BAR
      if(mp_bVertical == TRUE)
      { // Vertical bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_CENTER
#ifndef dCSP_SLIDERBAR_METHOD
        , CPoint(0, mp_nRightAff >> 1)
#else
        , CPoint(0, (mp_nLeftAff + mp_nRightAff) >> 1)
#endif // dCSP_SLIDERBAR_METHOD
        , ILD_NORMAL
        );
      }
      else
#endif // dCSP_VERTICAL_BAR
      { // Horizontal bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_CENTER
#ifndef dCSP_SLIDERBAR_METHOD
        , CPoint(mp_nRightAff >> 1, 0)
#else
        , CPoint((mp_nLeftAff + mp_nRightAff) >> 1, 0)
#endif // dCSP_SLIDERBAR_METHOD
        , ILD_NORMAL
        );
      }
    }

// CDE... Draw the before-left element
    // Before
#ifdef dCSP_SLIDERBAR_METHOD
    if(mp_nPrevLeftAff != mp_nLeftAff)
    {
      if(mp_nLeftAff > l_nStepPos)
      {
#ifdef dCSP_VERTICAL_BAR
        if(mp_bVertical == TRUE)
        { // Vertical bar
          mp_oBarImgLst.Draw
          ( &l_oDcProgress
          , cSPB_BEFORE
          , CPoint(0, mp_nLeftAff - l_nStepPos)
          , ILD_NORMAL
          );
        }
        else
#endif // dCSP_VERTICAL_BAR
        { // Horizontal bar
          mp_oBarImgLst.Draw
          ( &l_oDcProgress
          , cSPB_BEFORE
          , CPoint(mp_nLeftAff - l_nStepPos, 0)
          , ILD_NORMAL
          );
        }
      }else{}
    }else{}
#endif // dCSP_SLIDERBAR_METHOD

// CDF... Draw the after-right element
    // After
    if(mp_nRightAff != mp_nPrevRightAff)
    {
      if(mp_nRightAff < (mp_nEndAff - l_nStepPos))
      {
#ifdef dCSP_VERTICAL_BAR
        if(mp_bVertical == TRUE)
        { // Vertical bar
          mp_oBarImgLst.Draw
          ( &l_oDcProgress
          , cSPB_AFTER
          , CPoint(0, mp_nRightAff + l_nStepPos)
          , ILD_NORMAL
          );
        }
        else
#endif // dCSP_VERTICAL_BAR
        { // Horizontal bar
          mp_oBarImgLst.Draw
          ( &l_oDcProgress
          , cSPB_AFTER
          , CPoint(mp_nRightAff + l_nStepPos, 0)
          , ILD_NORMAL
          );
        }
      }else{}
    }else{}

// CDG... Draw the start element
    // Start
#ifdef dCSP_SLIDERBAR_METHOD
    if(mp_nPrevLeftAff  != mp_nLeftAff)
#else
    if(mp_nPrevRightAff != mp_nRightAff) // In non-<dCSP_SLIDERBAR_METHOD> mode, only the right end can move
#endif // dCSP_SLIDERBAR_METHOD
    {
#ifdef dCSP_SLIDERBAR_METHOD
      if(mp_nLeftAff  < (l_nStepPos << 1))
#else
      if(mp_nRightAff < (l_nStepPos << 1)) // In non-<dCSP_SLIDERBAR_METHOD> mode, only the right end can move
#endif // dCSP_SLIDERBAR_METHOD
      { // If the START element was over-written, refresh it
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_START
        , CPoint(0, 0)
        , ILD_NORMAL
        );
      }else{}
    }else{}

// CDH... Draw the end element
    // End
    if(mp_nPrevRightAff != mp_nRightAff)
    {
      if(mp_nRightAff > (mp_nEndAff - (l_nStepPos << 1)))
      { // If the END element was over-written, refresh it
#ifdef dCSP_VERTICAL_BAR
        if(mp_bVertical == TRUE)
        { // Vertical bar
          mp_oBarImgLst.Draw
          ( &l_oDcProgress
          , cSPB_END
          , CPoint(0, mp_nEndAff)
          , ILD_NORMAL
          );
        }
        else
#endif // dCSP_VERTICAL_BAR
        { // Horizontal bar
          mp_oBarImgLst.Draw
          ( &l_oDcProgress
          , cSPB_END
          , CPoint(mp_nEndAff, 0)
          , ILD_NORMAL
          );
        }
      }else{}
    }else{}

// CDI... Draw the left element of the bar
#ifdef dCSP_SLIDERBAR_METHOD
    if( // In case of slider display, the closeness of the RIGHT element from the LEFT can cause an over-write of the LEFT element with BAR and/or CENTER
           (mp_nPrevLeftAff != mp_nLeftAff)
        || (
               mp_nRightAff
             < (mp_nLeftAff + (l_nStepPos << 1))
           )
      )
    {
      // Position of the start of the bar
      mp_nPrevLeftAff = mp_nLeftAff;

#ifdef dCSP_VERTICAL_BAR
      if(mp_bVertical == TRUE)
      { // Vertical bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_TOP // Top
        , CPoint(0, mp_nLeftAff)
        , ILD_NORMAL
        );
      }
      else
#endif // dCSP_VERTICAL_BAR
      { // Horizontal bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_LEFT // Left
        , CPoint(mp_nLeftAff, 0)
        , ILD_NORMAL
        );
      }
    }else{}
#else
    // As long as the RIGHT element is too close from the LEFT element, the CENTER element over-writes the LEFT element, thus we have to refresh the LEFT element
    if(mp_nRightAff < (l_nStepPos << 1))
    {
#ifdef dCSP_VERTICAL_BAR
      if(mp_bVertical == TRUE)
      { // Vertical bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_TOP // Top
        , CPoint(0, 0)
        , ILD_NORMAL
        );
      }
      else
#endif // dCSP_VERTICAL_BAR
      { // Horizontal bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_LEFT // Left
        , CPoint(0, 0)
        , ILD_NORMAL
        );
      }
    }else{}
#endif // dCSP_SLIDERBAR_METHOD

// CDJ... Draw the right element of the bar
    if( // In case of slider display, the closeness of the LEFT element from the RIGHT can cause an over-write of the RIGHT element with BAR and/or CENTER
           (mp_nPrevRightAff != mp_nRightAff)
#ifdef dCSP_SLIDERBAR_METHOD
        || (
                mp_nLeftAff
             > (mp_nRightAff - (l_nStepPos << 1))
           )
#endif // dCSP_SLIDERBAR_METHOD
      )
    {
      // Position of the end of the bar
      mp_nPrevRightAff = mp_nRightAff;

#ifdef dCSP_VERTICAL_BAR
      if(mp_bVertical == TRUE)
      { // Vertical bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_BOTTOM // Bottom
        , CPoint(0, mp_nRightAff)
        , ILD_NORMAL
        );
      }
      else
#endif // dCSP_VERTICAL_BAR
      { // Horizontal bar
        mp_oBarImgLst.Draw
        ( &l_oDcProgress
        , cSPB_RIGHT // Right
        , CPoint(mp_nRightAff, 0)
        , ILD_NORMAL
        );
      }
    }else{}

    if(mp_nPrevEndAff != mp_nEndAff)
    {
      mp_nPrevEndAff = mp_nEndAff;
    }else{}
  }

// D..... Display the progress bar
  // Copy the progress bitmap each time the object have to be refreshed
#ifndef dCSP_DISPLAY_STRETCH
  l_oDC.BitBlt(0, 0, l_oRectPaint.Width(), l_oRectPaint.Height(), &l_oDcProgress, 0, 0, SRCCOPY);
#else
  CDC      l_oDcStretch;   // CompatibleDC
  CBitmap* l_poOldStretch; // l_oDC's previous bitmap
  BITMAP   sStretchBmp;

  l_oDcStretch.CreateCompatibleDC(&l_oDC);
	l_poOldStretch = l_oDcStretch.SelectObject(mp_poStretchBmp);

  mp_poStretchBmp->GetBitmap(&sStretchBmp);
  l_oDC.BitBlt(0, 0, sStretchBmp.bmWidth, sStretchBmp.bmHeight, &l_oDcStretch, 0, 0, SRCCOPY);

  l_oDcStretch.SelectObject(l_poOldStretch);
  l_oDcStretch.DeleteDC();
#endif // dCSP_DISPLAY_STRETCH

  // Release the DC
  l_oDcProgress.SelectObject(l_poOldBitmap);
  l_oDcProgress.DeleteDC();

//  EndPaint(sPaintStruct);
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : OnSizing                                                   */
/* Role          : Before things are resized                                  */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   fwSide : Edge of window to be moved                      */
/*                   pRect  : New rectangle                                   */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Resize the object                                      */
/*                 B - Resize the text                                        */
/*----------------------------------------------------------------------------*/
/* PROC OnSizing                                                              */
/*                                                                            */
/* A..... Resize the object                                                   */
/* B..... Resize the text                                                     */
/*----------------------------------------------------------------------------*/
/* In normal cases, this is NEVER called                                      */
/*--- END FUNCTION HEADER ----------------------------------------------------*/
void CSkinProgress::OnSizing
( UINT   fwSide // Edge of window to be moved
, LPRECT pRect  // New rectangle
)
{
// A..... Resize the object
	CStatic::OnSizing
  ( fwSide
  , pRect
  );

  // Process

// B..... Resize the text
  RefreshPanes(); // Recalculate text layout on sizing the window
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : OnSize                                                     */
/* Role          : Once things were resized                                   */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   nType : Type of resizing requested                       */
/*                   cx    : Width                                            */
/*                   cy    : Height                                           */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Transmit the new dimensions                            */
/*----------------------------------------------------------------------------*/
/* PROC OnSize                                                                */
/*                                                                            */
/* A..... Transmit the new dimensions                                         */
/*----------------------------------------------------------------------------*/
/* Just over-ridden, ready to use for various purposes ;)                     */
/*--- END FUNCTION HEADER ----------------------------------------------------*/
void CSkinProgress::OnSize
( UINT nType // Type of resizing requested 
, int  cx    // Width
, int  cy    // Height
)
{
// A..... Transmit the new dimensions
	CStatic::OnSize
  ( nType
  , cx
  , cy
  );
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          : OnTimer                                                    */
/* Role          : The object timer has elapsed                               */
/* Type          : PROTECTED                                                  */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   nIDEvent : The Timer handle that elapsed                 */
/* Pre-condition : None                                                       */
/* Constraints   : None                                                       */
/* Behavior      : A - Refresh the text and the progress bar                  */
/*                 B - Transmit the Timer handle to the parent                */
/*----------------------------------------------------------------------------*/
/* PROC OnTimer                                                               */
/*                                                                            */
/* A..... Refresh the text and the progress bar                               */
/* B..... Transmit the Timer handle to the parent                             */
/*----------------------------------------------------------------------------*/
/* Just used to refresh the timed message when things are going too slow...   */
/* Also used when on time redrawing the progress bar, to limit to 50 refresh  */
/* per second...                                                              */
/*--- END FUNCTION HEADER ----------------------------------------------------*/
void CSkinProgress::OnTimer
( UINT nIDEvent
)
{ // On a Timer event
  if(nIDEvent == (UINT) this) // Use object's unique address as timer identifier
  {
// A..... Refresh the text and the progress bar
    RefreshPanes(); // Refresh the whole stuff, each 500 ms or 20 ms if in dCSP_TIMED_REDRAW mode
  }else{}

// B..... Transmit the Timer handle to the parent	
	CStatic::OnTimer(nIDEvent);
}
