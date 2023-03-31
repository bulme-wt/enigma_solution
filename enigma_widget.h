#pragma once

#include "plugboard.h"

#include <QVBoxLayout>
#include <QWidget>

class LampsWidget;

class EnigmaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EnigmaWidget(QWidget *parent = nullptr);

private slots:
    void buttonPressed(char letter, bool enable);

private:
    QVBoxLayout m_main_layout;
    LampsWidget* m_lamps;
    PlugBoard m_plugboard;
};

