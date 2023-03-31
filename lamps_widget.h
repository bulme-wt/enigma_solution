#pragma once

#include <QWidget>
#include <QGridLayout>

#include <map>
class QLabel;
class LampsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LampsWidget(int width, QWidget *parent = nullptr);

public slots:
    void enableLamp(char letter, bool enable = true);

private:
    const int m_width;
    QGridLayout m_layout;
    std::map<char, QLabel*> m_lamps;
};

