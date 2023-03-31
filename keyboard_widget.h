#pragma once

#include <QWidget>
#include <QGridLayout>

#include <map>

class QPushButton;
class KeyboardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KeyboardWidget(int width, QWidget *parent = nullptr);

signals:
    void buttonPressed(char letter, bool pressed);

private slots:
    void onButtonPressed();
    void onButtonReleased();
private:
    const int m_width;
    QGridLayout m_layout;
    std::map<char, QPushButton*> m_buttons;
};

