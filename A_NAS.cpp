
// A_NAS.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "A_NAS.h"
#include "A_NASDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CANASApp

BEGIN_MESSAGE_MAP(CANASApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CANASApp construction

CANASApp::CANASApp()
{
	// ��������� ��������� �����������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// ��������� ��� �������� ������������� � InitInstance
}


// The one and only CANASApp object

CANASApp theApp;


// CANASApp initialization

BOOL CANASApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ���������� ��� ��������, ����� �������� ��� ����� ������ ����������, ������� �� ������ ������������
	// � ����� ����������
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();


	// ������ �������� ��������, ���� ������ ��������
	// ����� ������������� ������ �������� ��� �������� ���������� �������������� ������ ��������.
	CShellManager *pShellManager = new CShellManager;

	// ���������� ���������� �������� �Windows Native� ��� ��������� ��� � ��������� ���������� MFC.
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ����������� �������������
	// ���� �� �� ����������� ��� ������� � ������ ��������� ������
	// ������ �������������� ������������ �����, ��� ������� ������� �� ����������
	// ���������� ��������� �������������, ������� ��� �� �����
	// �������� ���� �������, ��� ������� �������� ���� ���������
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CANASDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// ������� ��������� ���� �������� ��������.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// ��������� ������ ������, ���������� FALSE, ����� �� ����� ��
	// ����������, � �� ��������� ����� ��������� ����������
	return FALSE;
}

