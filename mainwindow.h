#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>

namespace widgets
{
class generator_widget;
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void init();
    void init_generator();
private:
    Ui::MainWindow *ui;
    QWidget* m_main_widget;
    QTabWidget* m_main_tab_widget;
    widgets::generator_widget* m_generator_widget;
};
#endif // MAINWINDOW_H
