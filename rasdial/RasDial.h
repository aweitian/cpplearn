// RasDial.h : main header file for the RASDIAL application 
// 
 
#if !defined(AFX_RASDIAL_H__72701242_7147_4709_8770_860D9E794AD7__INCLUDED_) 
#define AFX_RASDIAL_H__72701242_7147_4709_8770_860D9E794AD7__INCLUDED_ 
 
#if _MSC_VER > 1000 
#pragma once 
#endif // _MSC_VER > 1000 
 
#ifndef __AFXWIN_H__ 
	#error include 'stdafx.h' before including this file for PCH 
#endif 
 
#include "resource.h"		// main symbols 
 
///////////////////////////////////////////////////////////////////////////// 
// CRasDialApp: 
// See RasDial.cpp for the implementation of this class 
// 
 
class CRasDialApp : public CWinApp 
{ 
public: 
	CRasDialApp(); 
 
// Overrides 
	// ClassWizard generated virtual function overrides 
	//{{AFX_VIRTUAL(CRasDialApp) 
	public: 
	virtual BOOL InitInstance(); 
	//}}AFX_VIRTUAL 
 
// Implementation 
 
	//{{AFX_MSG(CRasDialApp) 
		// NOTE - the ClassWizard will add and remove member functions here. 
		//    DO NOT EDIT what you see in these blocks of generated code ! 
	//}}AFX_MSG 
	DECLARE_MESSAGE_MAP() 
}; 
 
 
///////////////////////////////////////////////////////////////////////////// 
 
//{{AFX_INSERT_LOCATION}} 
// Microsoft Visual C++ will insert additional declarations immediately before the previous line. 
 
#endif // !defined(AFX_RASDIAL_H__72701242_7147_4709_8770_860D9E794AD7__INCLUDED_)