#include "mainwindow.h"
#include "enigma_widget.h"

#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setCentralWidget(new EnigmaWidget{this});
}

MainWindow::~MainWindow()
{
}

