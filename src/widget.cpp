#include "widget.h"
#include "./ui_widget.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QBuffer>

Widget::Widget(QWidget *parent)
    : QWidget(parent) , ui(new Ui::Widget)//, m_singletonImg(nullptr)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setImageMtx(Matrix_uint16 matrix) { m_vectMatrixImg.push_back(matrix); }

void Widget::on_checkBox_grayScale_stateChanged(int arg1)
{
}


void Widget::on_checkBox_improveContrast_stateChanged(int arg1)
{
    QMessageBox::warning(this, "Processing", "improveContrast");
}


void Widget::on_checkBox_reduceSize_stateChanged(int arg1)
{
    QMessageBox::warning(this, "Processing", "reduceSize");
}


void Widget::on_checkBox_increaseSize_stateChanged(int arg1)
{

}

void Widget::on_pushButton_uploadImg_clicked()
{
    std::vector<QImage> images;
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Open image", "", "Images (*.png *.jpg *.bmp)");
}
void Widget::on_pushButton_cancel_clicked()
{
    //clearImages("all");
}

void Widget::on_pushButton_procesImg_clicked()
{
    imgProcess img;
    std::vector<QImage> outputImg;
    std::vector<std::string> names;
}


void Widget::on_pushButton_downloadImg_clicked()
{
    //clearImages("all");
}


