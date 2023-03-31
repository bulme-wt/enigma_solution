#include "lamps_widget.h"

#include <QLabel>

LampsWidget::LampsWidget(int width, QWidget *parent)
    : QWidget{parent}
    , m_width{width}
    , m_layout{this}
{
    int row = 0;
    int col = 0;
    for(char c = 'A'; c <= 'Z'; c++)
    {
        auto lamp = new QLabel(QChar(c));
        lamp->setMinimumSize(60, 60);
        lamp->setMaximumSize(60, 60);
        lamp->setAlignment(Qt::AlignCenter);
        lamp->setStyleSheet("background-color:#111111; color:#CCCCCC; border-radius:25; font-size:24px; font-weight: bold; border: 3px solid gray");
        m_layout.addWidget(lamp, row, col);
        m_lamps[c] = lamp;
        if (++col >= m_width)
        {
            col = 0;
            row++;
        }
    }
}

void LampsWidget::enableLamp(char letter, bool enable)
{
    if (enable)
    {
        m_lamps.at(letter)->setStyleSheet("background-color:#CCCC00; color:#111111; border-radius:25; font-size:24px; font-weight: bold; border: 3px solid gray");
    }
    else
    {
        m_lamps.at(letter)->setStyleSheet("background-color:#111111; color:#CCCCCC; border-radius:25; font-size:24px; font-weight: bold; border: 3px solid gray");
    }
}
