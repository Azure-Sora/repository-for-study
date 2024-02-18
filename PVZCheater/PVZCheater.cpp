#include "PVZCheater.h"


PVZCheater::PVZCheater(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PVZCheaterClass())
{
    ui->setupUi(this);

    init();

    connect(ui->btn_setSunshine, &QPushButton::clicked, this, &PVZCheater::modifySunshine);
    connect(ui->action_refresh, &QAction::triggered, [&]() {
        init();
        });
}

PVZCheater::~PVZCheater()
{
    delete ui;
}

void PVZCheater::init()
{
    gameProcess = getProcessID();
    findSunshineAddress();
    ui->label_nowSunshine->setText(QString::number(getSunshine()));
}

HANDLE PVZCheater::getProcessID()
{
    HWND gameHwnd = FindWindowW(NULL, L"植物大战僵尸中文版");
    DWORD pid;
    GetWindowThreadProcessId(gameHwnd, &pid);
    HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
    return process;
}

int PVZCheater::getSunshine()
{
    DWORD sunshineNum;
    ReadProcessMemory(gameProcess, (LPVOID)sunshineAddress, &sunshineNum, sizeof(DWORD), NULL);
    return sunshineNum;
}

void PVZCheater::modifySunshine()
{
    int modifyNum = ui->input_editSunshine->text().toInt();
    WriteProcessMemory(gameProcess, (LPVOID)sunshineAddress, &modifyNum, sizeof(DWORD), NULL);
    ui->label_nowSunshine->setText(QString::number(getSunshine()));
}

void PVZCheater::findSunshineAddress()
{
    DWORD base, firstOffset, finalAddress;
    ReadProcessMemory(gameProcess, (LPVOID)sunshineBaseAddress , &base, sizeof(DWORD), NULL);
    ReadProcessMemory(gameProcess, (LPVOID)(base + sunshineFirstOffset), &firstOffset, sizeof(DWORD), NULL);
    finalAddress = firstOffset + sunshineSecondOffset;
    sunshineAddress = finalAddress;
}


