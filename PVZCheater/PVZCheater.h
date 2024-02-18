#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PVZCheater.h"
#include<Windows.h>
#include<stdio.h>

QT_BEGIN_NAMESPACE
namespace Ui { class PVZCheaterClass; };
QT_END_NAMESPACE

class PVZCheater : public QMainWindow
{
    Q_OBJECT

public:
    PVZCheater(QWidget *parent = nullptr);
    ~PVZCheater();

    HANDLE gameProcess;
    DWORD sunshineAddress;

    void init();
    HANDLE getProcessID();
    int getSunshine();
    void modifySunshine();
    void findSunshineAddress();

    DWORD sunshineBaseAddress = 0x006A9EC0;
    DWORD sunshineFirstOffset = 0x768;
    DWORD sunshineSecondOffset = 0x5560;

private:
    Ui::PVZCheaterClass *ui;
};
