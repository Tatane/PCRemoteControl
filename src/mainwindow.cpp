#include "mainwindow.h"

const QColor stateColorOFF("#FF4515");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
#ifndef Q_OS_ANDROID
    setGeometry(1000, 500, 200, 300);
#endif

    // Configure layout :
    setCentralWidget(new QWidget(this));
    mLayout = new QVBoxLayout();
    centralWidget()->setLayout(mLayout);

    // Create buttons
    mBtnWakeUp = new QPushButton("Wake up PC", this);
    mLayout->addWidget(mBtnWakeUp);

    mBtnTestIfReady = new QPushButton("Test if ready", this);
    mLayout->addWidget(mBtnTestIfReady);

    mBtnShutDown = new QPushButton("Shut down PC", this);
    mLayout->addWidget(mBtnShutDown);

    mBtnSettings = new QPushButton("Settings", this);
    mLayout->addWidget(mBtnSettings);

    mLblState = new QLabel("Etat PC", this);
    mLayout->addWidget(mLblState);
    mLblState->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    mLblState->setStyleSheet("border: 2px solid");
    setStateColor(true);

    //mLayout->addStretch();

    initConnects();



}

MainWindow::~MainWindow()
{
}

void MainWindow::setStateColor(bool stateON)
{
    QString styleSheet("QLabel { background-color:%1; }");
    styleSheet = styleSheet.arg(stateColorOFF.name());
    mLblState->setStyleSheet(styleSheet);
}

void MainWindow::initConnects()
{
    connect(mBtnWakeUp, SIGNAL(clicked()), this, SLOT(onBtnWakeUp()));
    connect(mBtnTestIfReady, SIGNAL(clicked()), this, SLOT(onBtnTestIfReady()));
    connect(mBtnShutDown, SIGNAL(clicked()), this, SLOT(onBtnShutDown()));
    connect(mBtnSettings, SIGNAL(clicked()), this, SLOT(onBtnSettings()));
}

void MainWindow::onBtnWakeUp()
{
    mTcpClient = TCPClient::getInstance();
    mTcpClient->wakeUpComputer(QHostAddress("90.50.99.30"), "6c:f0:49:7c:ac:3c");
}

void MainWindow::onBtnTestIfReady()
{

}

void MainWindow::onBtnShutDown()
{

}

void MainWindow::onBtnSettings()
{

}
