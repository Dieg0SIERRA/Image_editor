#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void setImageMtx(Matrix_uint16 matrix);

private slots:

    void on_checkBox_grayScale_stateChanged(int arg1);
    void on_checkBox_improveContrast_stateChanged(int arg1);
    void on_checkBox_reduceSize_stateChanged(int arg1);
    void on_checkBox_increaseSize_stateChanged(int arg1);
    void on_pushButton_uploadImg_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_procesImg_clicked();
    void on_pushButton_downloadImg_clicked();

private:
    Ui::Widget *ui;
    std::vector<Matrix_uint16> m_vectMatrixImg;
};
#endif // WIDGET_H

