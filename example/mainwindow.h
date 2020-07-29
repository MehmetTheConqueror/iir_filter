#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "../iir_filter/iir_filter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    iir_filter* my_iir_filter;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int stirEffect;
    const float mean = 0.0;
    const float stddev = 3.0;
    std::default_random_engine generator;

private slots:
    void timer_tick();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
