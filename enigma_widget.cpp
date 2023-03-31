#include "enigma_widget.h"

#include "keyboard_widget.h"
#include "lamps_widget.h"
#include "plugboardwidget.h"

EnigmaWidget::EnigmaWidget(QWidget *parent)
    : QWidget{parent}
    , m_main_layout{this}
    , m_plugboard{{{'A', 'B'}, {'K', 'H'} }}
{
    const int KB_WIDTH{7};
    m_lamps = new LampsWidget{KB_WIDTH};
    auto kb = new KeyboardWidget{KB_WIDTH};
    auto pbw = new PlugBoardWidget{m_plugboard, 13};

    m_main_layout.addWidget(m_lamps);
    m_main_layout.addWidget(kb);
    m_main_layout.addWidget(pbw);
    connect(kb, SIGNAL(buttonPressed(char,bool)), this, SLOT(buttonPressed(char,bool)));
}

void EnigmaWidget::buttonPressed(char letter, bool enable)
{
    m_lamps->enableLamp(m_plugboard.encrypt(letter), enable);
}
