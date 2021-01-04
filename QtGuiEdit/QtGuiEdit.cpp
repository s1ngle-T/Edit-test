#include "QtGuiEdit.h"
#include <qt_windows.h>

#include <QtWidgets/QWidget>
#include <qt_windows.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qline.h>
#include <tlhelp32.h>
#include <qobject.h>
#include <qtableview.h>
#include <qstandarditemmodel.h>
#include <qpainter.h>
#include <qdesktopwidget.h>
#include <qsystemtrayicon.h>
#include <QMouseEvent>
#include <windows.h>        //注意头文件
#include <windowsx.h>

const DWORD KONEK = 1024;
const DWORD KPAGE = 4 * KONEK;
const DWORD KONEG = KONEK * KONEK * KONEK;

QStandardItemModel* OpenProcess_model = new QStandardItemModel();
QStandardItemModel* FindProcess_model = new QStandardItemModel();

QtGuiEdit::QtGuiEdit(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    //resize(700, 800);
    //连接
    connect(ui.FlushButton,SIGNAL(clicked(bool)),this,SLOT(FlushClick()));

    connect(ui.CloseButton, SIGNAL(clicked(bool)), this, SLOT(KillClick()));
    connect(ui.FindButton, SIGNAL(clicked(bool)), this, SLOT(FindAdd()));
    connect(ui.EditButton_2, SIGNAL(clicked(bool)), this, SLOT(EditProcess()));

    //模型连接
    ui.progressBar->setValue(0);
   //ui.progressBar->setVisible(false);
    //ui.progressBar->setValue(50);
    ui.progressBar->setMinimum(0);
    ui.progressBar->setMaximum(100);

    OpenProcess_model->setHorizontalHeaderLabels(QStringList() << "ProcessName" << "ProcessID");
    ui.ShowProcessList->setModel(OpenProcess_model);
    ui.ShowProcessList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui.ShowProcessList->setAlternatingRowColors(true);
    ui.ShowProcessList->horizontalHeader()->setStretchLastSection(true);
    ui.ShowProcessList->verticalHeader()->setDefaultSectionSize(25);
    ui.ShowProcessList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui.ShowProcessList->setMouseTracking(true);
    //ui.ShowProcessList->selectRow(2);


    FindProcess_model->setHorizontalHeaderLabels(QStringList() << "ProcessAddr");
    ui.ShowAdd->setModel(FindProcess_model);
    ui.ShowAdd->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui.ShowAdd->setAlternatingRowColors(true);
    ui.ShowAdd->horizontalHeader()->setStretchLastSection(true);
    ui.ShowAdd->verticalHeader()->setDefaultSectionSize(25);
    ui.ShowAdd->setEditTriggers(QAbstractItemView::NoEditTriggers);
 /*   ui.ShowAdd->setMouseTracking(true);
    ui.ShowAdd->selectRow(2);*/

   //GetProcessList();

}

DWORD AddList[KPAGE] = { 0 };
DWORD AddListCounter = 0;
DWORD AddListMax = KPAGE;


static DWORD flag = 0;
static DWORD count = 0;
static DWORD secondcount = 0;

BOOL QtGuiEdit::GetProcessList()
{


    HANDLE hProcessSnap;
    HANDLE hProcess;
    PROCESSENTRY32 pe32;
    DWORD dwPriorityClass;

    // Take a snapshot of all processes in the system.
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
       // printError(TEXT("CreateToolhelp32Snapshot (of processes)"))
        
       // QMessageBox::information(NULL, QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("获取进程失败"),QMessageBox::ok);

        return(FALSE);
    }

    // Set the size of the structure before using it.
    pe32.dwSize = sizeof(PROCESSENTRY32);

    // Retrieve information about the first process,
    // and exit if unsuccessful
    if (!Process32First(hProcessSnap, &pe32))
    {
       // printError(TEXT("Process32First")); // show cause of failure


        CloseHandle(hProcessSnap);          // clean the snapshot object
        return(FALSE);
    }

    // Now walk the snapshot of processes, and
    // display information about each process in turn
    int RowCount = 0;
    do
    {
   

        //_tprintf(TEXT("\n\n====================================================="));


       // _tprintf(TEXT("\nPROCESS NAME:  %s"), pe32.szExeFile);
        QString proName = QString::fromWCharArray(pe32.szExeFile);
        QStandardItem* itemName = new QStandardItem(proName);
        OpenProcess_model->setItem(RowCount,0, itemName);



        //_tprintf(TEXT("\n"));


        /* _tprintf(TEXT("\n-------------------------------------------------------"));*/

         // Retrieve the priority class.
        dwPriorityClass = 0;
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
        if (hProcess == NULL)
            //  printError(TEXT("OpenProcess"));
            ;

        else
        {
            dwPriorityClass = GetPriorityClass(hProcess);
            if (!dwPriorityClass)
               // printError(TEXT("GetPriorityClass"));

            CloseHandle(hProcess);
        }

        //_tprintf(TEXT("\n  Process ID        = %d\n"), pe32.th32ProcessID);

        QString proNum = QString::number(pe32.th32ProcessID, 10);
        QStandardItem* itemNum = new QStandardItem(proNum);
        OpenProcess_model->setItem(RowCount, 1, itemNum);

        RowCount++;


        /*_tprintf(TEXT("\n  Thread count      = %d"), pe32.cntThreads);
        _tprintf(TEXT("\n  Parent process ID = 0x%08X"), pe32.th32ParentProcessID);
        _tprintf(TEXT("\n  Priority base     = %d"), pe32.pcPriClassBase);*/
        /*  if (dwPriorityClass)
              _tprintf(TEXT("\n  Priority class    = %d"), dwPriorityClass);*/

              // List the modules and threads associated with this process
             // ListProcessModules(pe32.th32ProcessID);
              //ListProcessThreads(pe32.th32ProcessID);

    } while (Process32Next(hProcessSnap, &pe32));

    CloseHandle(hProcessSnap);
    return(TRUE);
}

void QtGuiEdit::FlushClick()
{
    GetProcessList();
}

void  QtGuiEdit::KillClick()
{
    DWORD ProcessId = ui.InputProcessId->text().toInt();

    if (ProcessId == NULL)
    {
        QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的进程号"), QMessageBox::Ok);
        return;
    }

    HANDLE  hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);
    while (hProcess == NULL)
    {
         QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的进程号"), QMessageBox::Ok);
         //cin >> dwId;
         break;
    }
   
    if (hProcess != NULL)
    {
        TerminateProcess(hProcess, 0);
        QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("进程已关闭"), QMessageBox::Ok);
        CloseHandle(hProcess);
        
    }


    //KillProcess(ProcessId);
}

void  QtGuiEdit::FindAdd()
{
    DWORD ProcessId = ui.InputProcessId->text().toInt();
    HANDLE  hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);
    DWORD value = ui.InputFindValue1->text().toInt();

    if (flag == 0)
    {
        AddList[KPAGE] = { 0 };
        AddListCounter = 0;
        //DWORD ProcessId = ui.InputProcessId->text().toInt();
        if (ProcessId == NULL)
        {
            QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的进程号"), QMessageBox::Ok);
            return;
        }
        // DWORD dwId = 0;
         /*DWORD value = 0;*/
        //DWORD value = ui.InputFindValue1->text().toInt();
        if (value == NULL)
        {
            QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入要查找的值"), QMessageBox::Ok);
            return;
        }

        if (hProcess == NULL)
        {
            QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的进程号"), QMessageBox::Ok);
            //cin >> dwId;
            return;
        }
       
        FirstFind(hProcess, value, AddList, &AddListCounter, AddListMax);
        ShowAddList(AddList, AddListCounter);
        ui.progressBar->setValue(0);
        flag = 1;
        secondcount = 0;
        count = 0;
        //free(AddList);
    }
   
    if (count == 0)
    {
        ui.InputFindValue1->clear();
       /* FindProcess_model->removeRows(0, FindProcess_model->rowCount());*/
        QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请再次输入要查找的值"), QMessageBox::Ok);
    }
    if (secondcount == 1)
    {
       /* ui.InputFindValue1->clear();*/
        count = 0;
        FindProcess_model->removeRows(0, FindProcess_model->rowCount());
        if (value == NULL)
        {
            QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请再次输入要查找的值"), QMessageBox::Ok);
            return;
        }

        NextFind(hProcess, value, AddList, &AddListCounter, AddListMax);
        //free(AddList);
        ShowAddList(AddList, AddListCounter);
        if (AddListCounter > 1)
        {
            QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("地址存在多个，建议重新查找"), QMessageBox::Ok);
        }
        if(AddListCounter ==1)
        QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("地址已锁定，若要修改进程，请输入要修改的值"), QMessageBox::Ok);
        flag = 0;
        
    }
  
    secondcount = 1;
    count = 1;
        return;
    
}

BOOL QtGuiEdit::EditProcess()
{
    DWORD ProcessId = ui.InputProcessId->text().toInt();
    HANDLE  hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);
    DWORD value = ui.InputEditValue->text().toInt();
    if (ProcessId == NULL)
    {
        QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的进程号"), QMessageBox::Ok);
        return false;
    }
    if (value == NULL)
    {
        QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的修改值"), QMessageBox::Ok);
        return false;
    }
    if (AddListCounter == 0||AddListCounter>1) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("地址无法锁定，建议重新查找"), QMessageBox::Ok);
        return false;
    }
    if (hProcess == NULL)
    {
        QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的进程号"), QMessageBox::Ok);
        //cin >> dwId;
        return false;
    }

    WriteMemoryList(hProcess, value, AddList, &AddListCounter);
   /* QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("修改成功"), QMessageBox::Ok);*/
    ui.InputFindValue1->clear();
    ui.InputProcessId->clear();
    ui.InputEditValue->clear();
    FindProcess_model->removeRows(0, FindProcess_model->rowCount());
    //free(AddList);
    AddList[KPAGE] = { 0 };
    AddListCounter = 0;
    return true;
}

void QtGuiEdit::ShowAddList(DWORD* AddList, DWORD AddListCounter)
{
    if (AddListCounter == 0)
    {
        QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("没有查找到地址"), QMessageBox::Ok);
        return;
    }
    //cout << endl << "---------AddListBEGIN:-----------" << endl;
    for (DWORD i = 0; i < AddListCounter; i++)
    {
       /* printf("%X\n", AddList[i]);*/
        QString ProAddr = QString::number(AddList[i]);
        QStandardItem* itemName = new QStandardItem(ProAddr);
        FindProcess_model->setItem(i, 0, itemName);
    }
    //cout << endl << "---------AddListEND:-----------" << endl;
   /* cout << endl << "找到了" << AddListCounter << "个数据" << endl;*/
    QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("找到了%1个数据").arg(AddListCounter), QMessageBox::Ok);


    return;

}

BOOL QtGuiEdit::CompareOnePage(HANDLE  hProcess, DWORD baseAdd, DWORD value, DWORD* AddList, DWORD* AddListCounter, const DWORD AddListMax)
{
    BYTE onePage[KPAGE] = { 0 };
    if (!ReadProcessMemory(hProcess, (LPCVOID)baseAdd, (LPVOID)onePage, KPAGE, NULL))
    {
        return TRUE;
    }

    DWORD* pdwPointer = NULL;
    pdwPointer = (DWORD*)onePage;
    for (DWORD i = 0; i < KONEK; i++)
    {
        if (*AddListCounter >= AddListMax)
        {
           // cout << "数据太多，无法查找" << endl;
            return FALSE;
        }
        if (pdwPointer[i] == value)
        {
            AddList[*AddListCounter] = baseAdd + i * sizeof(DWORD);
            (*AddListCounter)++;
        }
    }
    return TRUE;
}

BOOL QtGuiEdit::FirstFind(HANDLE  hProcess, DWORD value, DWORD* AddList, DWORD* AddListCounter, const DWORD AddListMax)
{
    
    DWORD totalPage = (2 * KONEG - 2 * KONEK) / KPAGE;
    for (DWORD Count = 64 * KONEK; Count < 2 * KONEG - 64 * KONEK; Count += 4 * KONEK)
    {
        CompareOnePage(hProcess, Count, value, AddList, AddListCounter, AddListMax);
        DWORD currentPage = (count - 64 * KONEK) / KPAGE + 1;
        DWORD currentProcess = (currentPage / totalPage) * 100;
       //QProgressBar * 
        ui.progressBar->setValue(currentProcess);
       

        //printf("\n Current process is ------%.21f%%-----", currentProcess)
    }

    return TRUE;
}

BOOL QtGuiEdit::NextFind(HANDLE hProcess, DWORD value, DWORD* AddList, DWORD* AddListCounter, const DWORD addrListMax) {
    DWORD a;
    DWORD newcounter = 0;
    for (int i = 0; i < *AddListCounter; i++)
        if (ReadProcessMemory(hProcess, (LPCVOID)AddList[i], &a, sizeof(DWORD), NULL) && a == value)
            AddList[newcounter++] = AddList[i];
    *AddListCounter = newcounter;
    return true;
}

void QtGuiEdit::WriteMemoryList(HANDLE hProcess, DWORD value, DWORD* AddrList, DWORD* AddListCounter)
{
    for (int i = 0; i < *AddListCounter; i++)
        if (!WriteProcessMemory(hProcess, (LPVOID)AddrList[i], &value, sizeof(DWORD), NULL))
            //printf("%X 写入失败\n", AddrList[i]);
        {
            QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("写入失败"), QMessageBox::Ok);
        }
           
        else
            QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("修改成功"), QMessageBox::Ok);
    return;
}









