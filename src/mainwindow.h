#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
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

    // Temporaire (sera surement dans la fenetre Settings
    QLineEdit * mTxtIP;
    QLineEdit * mTxtMacAdress;
    QLineEdit * mTxtPort;
    // Temporaire (Fin)

    QPushButton * mBtnWakeUp;
    QPushButton * mBtnTestIfReady;
    QPushButton * mBtnShutDown;
    QPushButton * mBtnSettings;

    QLabel * mLblState;

    QTextEdit * mTxtConsole;

    TCPClient * mTcpClient;

    void setStateColor(bool stateON);
    void initConnects();



private slots:
    void onBtnWakeUp();
    void onBtnTestIfReady();
    void onBtnShutDown();
    void onBtnSettings();
    void writeToConsole(QString texte);
};

#endif // MAINWINDOW_H
