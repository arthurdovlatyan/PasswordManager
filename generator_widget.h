#ifndef GENERATOR_WIDGET_H
#define GENERATOR_WIDGET_H

#include <QLineEdit>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>

#include "password_generator_engine.h"

namespace widgets {

class generator_widget : public QWidget
{
    Q_OBJECT
public:
    explicit generator_widget(QWidget *parent = nullptr);

signals:

public slots:
    void on_generate_button_clicked();
    void on_size_val_change();
    void on_num_button_checked();
    void on_low_button_checked();
    void on_upp_button_checked();
    void on_special_button_checked();
    void on_clip_button_clicked(); // implement
private:
    void init();
    void init_pass(QVBoxLayout* l);
    void init_size(QVBoxLayout* l);
    void init_num(QVBoxLayout* l);
    void init_low(QVBoxLayout* l);
    void init_upp(QVBoxLayout* l);
    void init_special(QVBoxLayout* l);
    void init_apply(QVBoxLayout* l);

    void setup_connections();
private:
    QLineEdit* m_pass;
    QPushButton* m_clip;

    QLabel* m_size_label;
    QLineEdit* m_size;

    QLabel* m_number_label;
    QCheckBox* m_number_checkbox;

    QLabel* m_lowercase_label;
    QCheckBox* m_lowercase_checkbox;

    QLabel* m_uppercase_label;
    QCheckBox* m_uppercase_checkbox;

    QLabel* m_special_label;
    QCheckBox* m_special_checkbox;

    QPushButton* m_apply;

    typedef  password_generator_engine::password_generator_engine engine;
    engine& m_engine;
};


}
#endif // GENERATOR_WIDGET_H
