#include "qt_graphics.h"
#include "ui_qt_graphics.h"

qt_graphics::qt_graphics(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::qt_graphics)
{
    ui->setupUi(this);
}

qt_graphics::~qt_graphics()
{
    delete ui;
}


void qt_graphics::on_c0_clicked()
{
    this->setStyleSheet("background-color: rbg(255, 220, 220)");
}

void qt_graphics::on_c1_clicked()
{

}

void qt_graphics::on_c2_clicked()
{

}

void qt_graphics::on_c4_clicked()
{

}

void qt_graphics::on_c3_clicked()
{

}

void qt_graphics::on_c5_clicked()
{

}

void qt_graphics::on_c8_clicked()
{

}

void qt_graphics::on_c6_clicked()
{

}

void qt_graphics::on_c7_clicked()
{

}
