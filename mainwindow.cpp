#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_about.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::aboutQt()
 {
     QApplication::aboutQt();
 }

void MainWindow::about()
{
    QDialog *form=new QDialog();
    Ui::About myui;
    myui.setupUi(form);

    form->show();
}

void MainWindow::targetFunction(QString f)
{
    this->tfparser.parse(f);
}
