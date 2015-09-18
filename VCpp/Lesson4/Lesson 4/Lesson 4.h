
// Lesson 4.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLesson4App:
// See Lesson 4.cpp for the implementation of this class
//

class CLesson4App : public CWinApp
{
public:
	CLesson4App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLesson4App theApp;