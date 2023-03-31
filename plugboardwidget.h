#pragma once



#include <QGridLayout>
#include <QWidget>

class QPushButton;
class PlugBoard;

class PlugBoardWidget : public QWidget
{
public:
    PlugBoardWidget(PlugBoard& plugboard, int width, QWidget *parent = nullptr);

private slots:
    void onPlug();
private:
    PlugBoard& m_plugboard_model;
    const int m_width;
    QGridLayout m_layout;
    std::map<char, QPushButton*> m_jacks;
    char m_selected_jack = '\0';
};

