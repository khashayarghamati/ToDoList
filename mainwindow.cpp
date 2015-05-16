#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    showMaximized();

    FilePath = Path = AppPath.currentPath();
    _File = new QFile("/opt/ProgramApp.txt");

    connect(ui->Savebtn,SIGNAL(clicked()),this,SLOT(on_Savebtn_clicked()));
    connect(ui->Showbtn2,SIGNAL(clicked()),this,SLOT(on_Showbtn_clicked()));
    connect(ui->ShowButtom1,SIGNAL(clicked()),this,SLOT(on_ShowButtom1_clicked()));

    State=0;


}

MainWindow::~MainWindow()
{
    delete ui;
}


QString MainWindow::on_SetProgram_textChanged()
{
    return ui->SetProgram->toPlainText();
}

void MainWindow::on_Savebtn_clicked()
{
    QString _Program=on_SetProgram_textChanged();
    QTextStream in(_File);
    if(!_Program.isNull()){
        _File->open(QIODevice::WriteOnly);
        in<<_Program;
//        _File->write(_Program.toStdString().c_str(),_Program.size());
        _File->close();
    }
    else
    {
        //TODO Create Alert
    }
}


void MainWindow::on_Showbtn_clicked()
{
    _File->open(QIODevice::ReadOnly);

    QTextStream out(_File);

    if(State==0){
        ui->SetProgram->setText(out.readAll());
    }
    else
    {
        ui->ShowProgram->setText(out.readAll());
        State=0;
    }

    _File->close();
}

void MainWindow::on_ShowButtom1_clicked()
{
    State=1;
    on_Showbtn_clicked();
}
