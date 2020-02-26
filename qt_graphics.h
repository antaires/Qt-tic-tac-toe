#ifndef QT_GRAPHICS_H
#define QT_GRAPHICS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class qt_graphics; }
QT_END_NAMESPACE

class qt_graphics : public QMainWindow
{
    Q_OBJECT

public:
    qt_graphics(QWidget *parent = nullptr);
    ~qt_graphics();

private slots:
    void on_c0_clicked();

    void on_c1_clicked();

    void on_c2_clicked();

    void on_c4_clicked();

    void on_c3_clicked();

    void on_c5_clicked();

    void on_c8_clicked();

    void on_c6_clicked();

    void on_c7_clicked();

private:
    Ui::qt_graphics *ui;
};
#endif // QT_GRAPHICS_H
