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


    // Temporaire :
    mTxtIP = new QLineEdit("90.50.99.30", this);
    mLayout->addWidget(mTxtIP);

    mTxtMacAdress = new QLineEdit("6c:f0:49:7c:ac:3c", this);
    mLayout->addWidget(mTxtMacAdress);

    mTxtPort = new QLineEdit("45000", this);
    mLayout->addWidget(mTxtPort);

    mTxtConsole = new QTextEdit(this);
    mTxtConsole->setReadOnly(true);
    mLayout->addWidget(mTxtConsole);
    // Temporaire (Fin)

    //mLayout->addStretch();

    initConnects();


    // Client TCP :
    mTcpClient = TCPClient::getInstance();
    connect(mTcpClient, SIGNAL(writeToConsole(QString)), this, SLOT(writeToConsole(QString)));


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
    mTcpClient->wakeUpComputer(mTxtIP->text(), mTxtMacAdress->text(), mTxtPort->text().toInt());
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

void MainWindow::writeToConsole(QString texte)
{
    mTxtConsole->append(texte);
}
