#include "dialog.h"
#include "ui_dialog.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_createFileButton_clicked()
{
    QFile file("result.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "File open";
        QTextStream writeStream(&file);
        writeStream.setCodec("UTF-8");
        QString str = "Миру мир!";
        writeStream << str;
        file.close();
    }



    QApplication::exit();
}
