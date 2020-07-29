#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmath.h>
#include <QDebug>

#define SAMPLING_PERIOD 100     // ms

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->physicalValue->setValue(20);
    stirEffect = 0;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::timer_tick);
    timer->start(SAMPLING_PERIOD);

    std::vector<float> c_a, c_b;

    c_a.push_back(0.9);
    c_b.push_back(0.1);

    my_iir_filter = new iir_filter(c_a, c_b);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timer_tick()
{
    static int i=0;

    float stir = (stirEffect * (qrand()%5 - qrand()%5))/10.0;

    float gaussian_noise = 0.0;
    float sinusoidal_noise = 0.0;

    if (ui->chGaussianNoise->isChecked()) {
        std::normal_distribution<float> dist(0, ui->lnStdDev->text().toFloat());
        gaussian_noise += dist(generator);
    }

    if (ui->chSinusoidal->isChecked()) {
        float A = ui->lnAmplitude->text().toFloat();
        float f = ui->lnFrequency->text().toFloat();
        sinusoidal_noise = A*sin(2*M_PI*f*(i++)*SAMPLING_PERIOD/1000.0);
    }

    float realValue = ui->physicalValue->value();
    float noise = gaussian_noise + sinusoidal_noise;
    float input = realValue + noise + stir;
    float output = my_iir_filter->get_filter_output(input);

    ui->labelReal->setText(QString::number(realValue, 'f', 2));
    ui->labelInput->setText(QString::number(input, 'f', 2));
    ui->labelOutput->setText(QString::number(output, 'f', 2));

    ui->inputWithNoise->setValue(input);
    ui->filtredOutput->setValue(output);

    if (stirEffect > 0)
        stirEffect--;
}

void MainWindow::on_pushButton_clicked()
{
    stirEffect += 50;
}
