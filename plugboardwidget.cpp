#include "plugboardwidget.h"
#include "plugboard.h"
#include "qlabel.h"

#include <QPushButton>

PlugBoardWidget::PlugBoardWidget(PlugBoard &plugboard, int width, QWidget *parent)
    : QWidget(parent)
    , m_plugboard_model(plugboard)
    , m_width(width)
    , m_layout{this}
{
    int row = 0;
    int col = 0;
    for(char c = 'A'; c <= 'Z'; c++)
    {
        const int PLUG_SIZE = 25;
        auto jack = new QPushButton(QChar(c));
        jack->setMinimumSize(PLUG_SIZE, PLUG_SIZE);
        jack->setMaximumSize(PLUG_SIZE, PLUG_SIZE);
        if (m_plugboard_model.encrypt(c) == c)
        {
            jack->setStyleSheet("background-color:black; color:#CCCCCC; border-radius:5; font-size:10px; font-weight: bold; border: 5px solid gray");
        }
        else
        {
            jack->setStyleSheet("background-color:black; color:#CCCCCC; border-radius:5; font-size:10px; font-weight: bold; border: 5px solid yellow");
        }
        m_layout.addWidget(jack, row, col);
        m_jacks[c] = jack;
        if (++col >= m_width)
        {
            col = 0;
            row++;
        }

        connect(jack, &QPushButton::pressed, this, &PlugBoardWidget::onPlug);

    }
}

void PlugBoardWidget::onPlug()
{
    char letter = static_cast<QPushButton*>(sender())->text().front().toLatin1();
    if (m_selected_jack == '\0')
    {
        m_selected_jack = letter;
        m_jacks[letter]->setStyleSheet("background-color:black; color:#CCCCCC; border-radius:5; font-size:10px; font-weight: bold; border: 5px solid orange");
    }
    else
    {
        //FIXME: update plugboard
        m_jacks[m_selected_jack]->setStyleSheet("background-color:black; color:#CCCCCC; border-radius:5; font-size:10px; font-weight: bold; border: 5px solid yellow");
        m_jacks[letter]->setStyleSheet("background-color:black; color:#CCCCCC; border-radius:5; font-size:10px; font-weight: bold; border: 5px solid yellow");
        m_selected_jack = '\0';
    }
}
