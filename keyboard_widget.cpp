#include "keyboard_widget.h"

#include <QPushButton>

KeyboardWidget::KeyboardWidget(int width, QWidget *parent)
    : QWidget{parent}
    , m_width{width}
    , m_layout{this}
{
    int row = 0;
    int col = 0;
    for(char c = 'A'; c <= 'Z'; c++)
    {
        auto button = new QPushButton(QChar(c));
        connect(button, SIGNAL(pressed()), this, SLOT(onButtonPressed()));
        connect(button, SIGNAL(released()), this, SLOT(onButtonReleased()));

        button->setMinimumSize(60, 60);
        button->setMaximumSize(60, 60);
        //button->setStyleSheet("background-color:#111111; color:#CCCCCC; border-radius:25; font-size:24px; font-weight: bold;");
        button->setStyleSheet("font-size:24px; font-weight: bold;");
        m_layout.addWidget(button, row, col);
        m_buttons[c] = button;
        if (++col >= m_width)
        {
            col = 0;
            row++;
        }
    }
}

void KeyboardWidget::onButtonPressed()
{
    char letter = static_cast<QPushButton*>(sender())->text().front().toLatin1();
    emit buttonPressed(letter, true);
}

void KeyboardWidget::onButtonReleased()
{
    char letter = static_cast<QPushButton*>(sender())->text().front().toLatin1();
    emit buttonPressed(letter, false);
}
