#include "generator_widget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QIntValidator>
#include <QSizePolicy>

#include <iostream>

namespace widgets {

generator_widget::generator_widget(QWidget *parent)
    : QWidget{parent}
    , m_engine(engine::get())
{
    init();
    setup_connections();
}

void generator_widget::on_generate_button_clicked()
{
    //m_pass->setReadOnly(false);
    int i = m_size->text().toInt();
    if (i > 100) {
        m_size->setProperty("error", true);
        m_size->update();
        return;
    }
    if (m_lowercase_checkbox->checkState() == 0 &&
            m_uppercase_checkbox->checkState() == 0 &&
            m_number_checkbox->checkState() ==0 &&
            m_special_checkbox->checkState() == 0) {
        m_lowercase_checkbox-setProperty("error", true);
        m_lowercase_checkbox->update();
        m_uppercase_checkbox-setProperty("error", true);
        m_uppercase_checkbox->update();
        m_special_checkbox-setProperty("error", true);
        m_special_checkbox->update();
        m_number_checkbox-setProperty("error", true);
        m_number_checkbox->update();
        return;
    }
    m_pass->setText(QString::fromStdString(m_engine.generatePassword()));
    //m_pass->setReadOnly(true);
}

void generator_widget::on_size_val_change()
{
    int i = m_size->text().toInt();
    if (i > 100) {
        m_size->setProperty("error", true);
        m_size->update();
    }
    m_engine.setLength(m_size->text().toInt());
}

void generator_widget::on_num_button_checked()
{
    if (m_number_checkbox->isChecked()) {
        m_engine.setNumbers(true);
    } else {
        m_engine.setNumbers(false);
    }
}

void generator_widget::on_low_button_checked()
{
    if (m_lowercase_checkbox->isChecked()) {
        m_engine.setLowercase(true);
    } else {
        m_engine.setLowercase(false);
    }
}

void generator_widget::on_upp_button_checked()
{
    if (m_uppercase_checkbox->isChecked()) {
        m_engine.setUpercase(true);
    } else {
        m_engine.setUpercase(false);
    }
}

void generator_widget::on_special_button_checked()
{
    if (m_special_checkbox->isChecked()) {
        m_engine.setSpecial_char(true);
    } else {
        m_engine.setSpecial_char(false);
    }
}

void generator_widget::on_clip_button_clicked()
{

}

void generator_widget::init()
{
    QVBoxLayout* l = new QVBoxLayout(this);

    init_pass(l);
    init_size(l);
    init_num(l);
    init_low(l);
    init_upp(l);
    init_special(l);
    init_apply(l);

    setup_connections();
}

void generator_widget::init_pass(QVBoxLayout *l)
{
    QHBoxLayout* h = new QHBoxLayout();
    l->addLayout(h);

    m_pass = new QLineEdit();
    m_clip = new QPushButton();

    m_pass->setReadOnly(true);
    m_pass->setAlignment(Qt::AlignCenter);
    const QIcon i("../PasswordGenerator/clip.png");
    m_clip->setIcon(i);
    m_clip->setToolTip("Copy to Clipboard");

    h->addWidget(m_pass);
    h->addWidget(m_clip);
}

void generator_widget::init_size(QVBoxLayout *l)
{
    QHBoxLayout* h = new QHBoxLayout();
    l->addLayout(h);


    m_size_label = new QLabel("Password Length");
    m_size = new QLineEdit();
    QIntValidator* q = new QIntValidator(1, 100, m_size);
    q->setRange(1,100);
    m_size->setValidator(q);
    m_size->setText("10");
    m_size->setAlignment(Qt::AlignCenter);
    m_engine.setLength(m_size->text().toInt());
    //m_size->setFixedSize(40, m_size->sizeHint().height());

    h->addSpacing(50);
    h->addWidget(m_size_label);
    h->addWidget(m_size);
    h->addSpacing(50);

    h->setAlignment(Qt::AlignHCenter);
}

void generator_widget::init_num(QVBoxLayout *l)
{
    QHBoxLayout* h = new QHBoxLayout();
    l->addLayout(h);

    m_number_label = new QLabel("Include numbers");
    m_number_checkbox = new QCheckBox();
    m_number_checkbox->setChecked(true);

    h->addWidget(m_number_label);
    h->addWidget(m_number_checkbox);
    h->setAlignment(Qt::AlignHCenter);
}

void generator_widget::init_low(QVBoxLayout *l)
{
    QHBoxLayout* h = new QHBoxLayout();
    l->addLayout(h);

    m_lowercase_label = new QLabel("Include lowercase");
    m_lowercase_checkbox = new QCheckBox();
    m_lowercase_checkbox->setChecked(true);

    h->addWidget(m_lowercase_label);
    h->addWidget(m_lowercase_checkbox);
    h->setAlignment(Qt::AlignHCenter);
}

void generator_widget::init_upp(QVBoxLayout *l)
{
    QHBoxLayout* h = new QHBoxLayout();
    l->addLayout(h);

    m_uppercase_label = new QLabel("Include uppercase");
    m_uppercase_checkbox = new QCheckBox();
    m_uppercase_checkbox->setChecked(true);

    h->addWidget(m_uppercase_label);
    h->addWidget(m_uppercase_checkbox);
    h->setAlignment(Qt::AlignHCenter);
}

void generator_widget::init_special(QVBoxLayout *l)
{
    QHBoxLayout* h = new QHBoxLayout();
    l->addLayout(h);

    m_special_label = new QLabel("Include special");
    m_special_checkbox = new QCheckBox();
    m_special_checkbox->setChecked(true);

    h->addWidget(m_special_label);
    h->addWidget(m_special_checkbox);
    h->setAlignment(Qt::AlignHCenter);
}

void generator_widget::init_apply(QVBoxLayout *l)
{
    QHBoxLayout* h = new QHBoxLayout();
    l->addLayout(h);

    m_apply = new QPushButton("Generate");
    m_apply->setToolTip("Generate Password");

    h->addWidget(m_apply);
    h->setAlignment(Qt::AlignRight);

}

void generator_widget::setup_connections()
{
    connect(m_apply, SIGNAL(clicked()), this, SLOT(on_generate_button_clicked()));
    connect(m_size, SIGNAL(textEdited(const QString &)), this, SLOT(on_size_val_change()));
    connect(m_special_checkbox, SIGNAL(stateChanged(int)), this, SLOT(on_special_button_checked()));
    connect(m_number_checkbox, SIGNAL(stateChanged(int)), this, SLOT(on_num_button_checked()));
    connect(m_lowercase_checkbox,SIGNAL(stateChanged(int)) , this, SLOT(on_low_button_checked()));
    connect(m_uppercase_checkbox,SIGNAL(stateChanged(int)), this, SLOT(on_upp_button_checked()));
    connect(m_clip, SIGNAL(clicked()), this, SLOT(on_clip_button_clicked()));
}

}
