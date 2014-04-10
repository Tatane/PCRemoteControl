#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

#include <QLabel>

#include "TCPClient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QVBoxLayout * mLayout;

    QPushButton * mBtnWakeUp;
    QPushButton * mBtnTestIfReady;
    QPushButton * mBtnShutDown;
    QPushButton * mBtnSettings;

    QLabel * mLblState;

    TCPClient * mTcpClient;

    void setStateColor(bool stateON);
    void initConnects();



private slots:
    void onBtnWakeUp();
    void onBtnTestIfReady();
    void onBtnShutDown();
    void onBtnSettings();
};

#endif // MAINWINDOW_H
