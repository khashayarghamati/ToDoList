#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QString>
#include <QTextStream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    QString on_SetProgram_textChanged();

    void on_Savebtn_clicked();

    void on_Showbtn_clicked();

    void on_ShowButtom1_clicked();

private:
    Ui::MainWindow *ui;
    QFile* _File;
    QString Path,
            FilePath;

    QDir AppPath;
    int State;
};

#endif // MAINWINDOW_H
