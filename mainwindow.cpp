#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "generator_widget.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_main_widget(new QWidget)
    , m_main_tab_widget()
{
    ui->setupUi(this);
    this->setCentralWidget(m_main_widget);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    QVBoxLayout* l = new QVBoxLayout(this);
    m_main_widget->setLayout(l);
    m_main_tab_widget = new QTabWidget();
    l->addWidget(m_main_tab_widget);
    init_generator();
    setFixedSize(350,600);
    setWindowTitle("Password Generator");
}

void MainWindow::init_generator()
{
    m_generator_widget = new widgets::generator_widget();
    m_main_tab_widget->addTab(m_generator_widget, "Generator");
}

