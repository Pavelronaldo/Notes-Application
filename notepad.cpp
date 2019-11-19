#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printer)
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif
#include <QPrinter>
#endif
#endif
#include <QFont>
#include <QFontDialog>
#include <vector>
#include "notepad.h"
#include "ui_notepad.h"

static unsigned num;//Номер поточного Note
static std::vector<QString> Note,Archive,home,work,just_note;

Notepad::Notepad(QWidget *parent) : QMainWindow(parent),ui(new Ui::Notepad){//Конструктор класу Notepad
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    connect(ui->actionNew,      &QAction::triggered, this, &Notepad::newDocument);
    connect(ui->actionOpen,     &QAction::triggered, this, &Notepad::open);
    connect(ui->actionSave,     &QAction::triggered, this, &Notepad::save);
    connect(ui->actionSave_as,  &QAction::triggered, this, &Notepad::saveAs);
    connect(ui->actionPrint,    &QAction::triggered, this, &Notepad::print);
    connect(ui->actionCut,      &QAction::triggered, this, &Notepad::cut);
    connect(ui->actionUndo,     &QAction::triggered, this, &Notepad::undo);
    connect(ui->actionRedo,     &QAction::triggered, this, &Notepad::redo);
    connect(ui->actionAbout,    &QAction::triggered, this, &Notepad::about);
}
Notepad::~Notepad() {delete ui;}//Деструктор класу Notepad
//Print Note//Print one Note//Back//Next//Save Note//Save Archive//Print Archive//Clear//About
void Notepad::newDocument()//Print Note
{
    QString tmp="";
    for(auto a:Note)tmp+=a+"\n____________________________________________\n";
    ui->textEdit->setText(tmp);
}
void Notepad::open(){ui->textEdit->setText(Note[num]);}//Print one Note
void Notepad::undo(){ui->textEdit->setText(Note[num>0?--num:num]);}//Back
void Notepad::redo(){ui->textEdit->setText(Note[num<Note.size()-1?++num:num]);}//Next
void Notepad::save(){Note.push_back(ui->textEdit->toPlainText());}//Save Note
void Notepad::saveAs(){//Save Archive
    Archive.push_back(Note[num]);
    auto tmp=Note.begin();
    for(unsigned i=0;i<num;i++)tmp++;
    Note.erase(tmp);
}
void Notepad::print(){//Print Archive
    QString tmp="";
    for(auto a:Archive)tmp+=a+"\n____________________________________________\n";
    ui->textEdit->setText(tmp);
}
void Notepad::cut(){//Clear
    currentFile.clear();
    ui->textEdit->setText(QString());
}
void Notepad::about(){QMessageBox::about(this, tr("About"),tr("Lab <b>Notepad</b>.Created by Pavel """));}//About

void Notepad::on_actionHome_triggered()
{
    if(!Note.empty())home.push_back(Note[num]);
}

void Notepad::on_actionWork_triggered()
{
    if(!Note.empty())work.push_back(Note[num]);

}

void Notepad::on_actionJust_note_triggered()
{
    if(!Note.empty())just_note.push_back(Note[num]);
}

void Notepad::on_actionShow_home_triggered()
{
    QString tmp="";
    for(auto a:home)tmp+=a+"\n____________________________________________\n";
    ui->textEdit->setText(tmp);
}

void Notepad::on_actionShow_work_triggered()
{
    QString tmp="";
    for(auto a:work)tmp+=a+"\n____________________________________________\n";
    ui->textEdit->setText(tmp);
}

void Notepad::on_actionShow_just_note_triggered()
{
    QString tmp="";
    for(auto a:just_note)tmp+=a+"\n____________________________________________\n";
    ui->textEdit->setText(tmp);
}
