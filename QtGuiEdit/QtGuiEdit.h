#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiEdit.h"
#include <qt_windows.h>

class QtGuiEdit : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiEdit(QWidget *parent = Q_NULLPTR);

	BOOL GetProcessList();
	BOOL CompareOnePage(HANDLE  hProcess, DWORD baseAdd, DWORD value, DWORD* AddList, DWORD* AddCounter, const DWORD addListMax);
	void ShowAddList(DWORD* AddList, DWORD AddListCounter);
	BOOL FirstFind(HANDLE  hProcess, DWORD value, DWORD* AddList, DWORD* AddListCounter, const DWORD AddListMax);
	BOOL NextFind(HANDLE hProcess, DWORD value, DWORD* AddList, DWORD* AddListCounter, const DWORD addrListMax);
	void WriteMemoryList(HANDLE hProcess, DWORD value, DWORD* AddrList, DWORD* AddListCounter);

private slots:
	void FlushClick();
	void KillClick();
	void FindAdd();
	BOOL EditProcess();
private:
	Ui::QtGuiEditClass ui;
};
