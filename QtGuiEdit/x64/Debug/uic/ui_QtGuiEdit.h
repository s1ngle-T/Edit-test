/********************************************************************************
** Form generated from reading UI file 'QtGuiEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIEDIT_H
#define UI_QTGUIEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiEditClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QTableView *ShowProcessList;
    QPushButton *FlushButton;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QTableView *ShowAdd;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_id;
    QLineEdit *InputProcessId;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_value;
    QLineEdit *InputFindValue1;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lable_EditValue;
    QLineEdit *InputEditValue;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *CloseButton;
    QPushButton *FindButton;
    QPushButton *EditButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiEditClass)
    {
        if (QtGuiEditClass->objectName().isEmpty())
            QtGuiEditClass->setObjectName(QStringLiteral("QtGuiEditClass"));
        QtGuiEditClass->resize(1234, 819);
        centralWidget = new QWidget(QtGuiEditClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_7 = new QHBoxLayout(centralWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ShowProcessList = new QTableView(centralWidget);
        ShowProcessList->setObjectName(QStringLiteral("ShowProcessList"));
        ShowProcessList->setStyleSheet(QLatin1String("QTableView{\n"
"\n"
"\n"
"	border-color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout->addWidget(ShowProcessList);

        FlushButton = new QPushButton(centralWidget);
        FlushButton->setObjectName(QStringLiteral("FlushButton"));

        verticalLayout->addWidget(FlushButton);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        ShowAdd = new QTableView(centralWidget);
        ShowAdd->setObjectName(QStringLiteral("ShowAdd"));
        ShowAdd->setStyleSheet(QLatin1String("QTableView{\n"
"\n"
"	border-color: rgb(255, 255, 255);\n"
"\n"
"\n"
"}"));

        verticalLayout_3->addWidget(ShowAdd);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setStyleSheet(QLatin1String("QProgressBar\n"
"{\n"
"text-align:center;\n"
"	background-color: rgb(0, 0, 127);\n"
"}"));
        progressBar->setValue(24);

        horizontalLayout_5->addWidget(progressBar);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_id = new QLabel(centralWidget);
        label_id->setObjectName(QStringLiteral("label_id"));

        horizontalLayout->addWidget(label_id);

        InputProcessId = new QLineEdit(centralWidget);
        InputProcessId->setObjectName(QStringLiteral("InputProcessId"));

        horizontalLayout->addWidget(InputProcessId);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_value = new QLabel(centralWidget);
        label_value->setObjectName(QStringLiteral("label_value"));

        horizontalLayout_2->addWidget(label_value);

        InputFindValue1 = new QLineEdit(centralWidget);
        InputFindValue1->setObjectName(QStringLiteral("InputFindValue1"));

        horizontalLayout_2->addWidget(InputFindValue1);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lable_EditValue = new QLabel(centralWidget);
        lable_EditValue->setObjectName(QStringLiteral("lable_EditValue"));

        horizontalLayout_4->addWidget(lable_EditValue);

        InputEditValue = new QLineEdit(centralWidget);
        InputEditValue->setObjectName(QStringLiteral("InputEditValue"));

        horizontalLayout_4->addWidget(InputEditValue);


        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        CloseButton = new QPushButton(centralWidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));

        horizontalLayout_3->addWidget(CloseButton);

        FindButton = new QPushButton(centralWidget);
        FindButton->setObjectName(QStringLiteral("FindButton"));
        FindButton->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"\n"
"}"));

        horizontalLayout_3->addWidget(FindButton);

        EditButton_2 = new QPushButton(centralWidget);
        EditButton_2->setObjectName(QStringLiteral("EditButton_2"));

        horizontalLayout_3->addWidget(EditButton_2);


        verticalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout_4);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        QtGuiEditClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiEditClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1234, 30));
        QtGuiEditClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiEditClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiEditClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiEditClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiEditClass->setStatusBar(statusBar);

        retranslateUi(QtGuiEditClass);

        QMetaObject::connectSlotsByName(QtGuiEditClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiEditClass)
    {
        QtGuiEditClass->setWindowTitle(QApplication::translate("QtGuiEditClass", "QtGuiEdit", Q_NULLPTR));
        FlushButton->setText(QApplication::translate("QtGuiEditClass", "\345\210\267\346\226\260\350\277\233\347\250\213", Q_NULLPTR));
        label->setText(QApplication::translate("QtGuiEditClass", "\346\255\243\345\234\250\350\277\233\350\241\214", Q_NULLPTR));
        label_id->setText(QApplication::translate("QtGuiEditClass", "\350\276\223\345\205\245\350\277\233\347\250\213\347\232\204ID", Q_NULLPTR));
        label_value->setText(QApplication::translate("QtGuiEditClass", "\350\276\223\345\205\245\346\237\245\346\211\276\347\232\204\345\200\274", Q_NULLPTR));
        lable_EditValue->setText(QApplication::translate("QtGuiEditClass", "\351\234\200\350\246\201\344\277\256\346\224\271\347\232\204\345\200\274", Q_NULLPTR));
        CloseButton->setText(QApplication::translate("QtGuiEditClass", "\345\205\263\351\227\255", Q_NULLPTR));
        FindButton->setText(QApplication::translate("QtGuiEditClass", "\346\237\245\346\211\276", Q_NULLPTR));
        EditButton_2->setText(QApplication::translate("QtGuiEditClass", "\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGuiEditClass: public Ui_QtGuiEditClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIEDIT_H
