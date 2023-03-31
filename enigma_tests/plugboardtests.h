#pragma once
#include <QtTest>
class PlugboardTests : public QObject
{
    Q_OBJECT

public:
    PlugboardTests();
    ~PlugboardTests();

private slots:
    void plugboard_test_case0();
    void plugboard_test_case1();
    void plugboard_test_case2();

    void plugboard_plug_cable_test_case_1();
    void plugboard_plug_cable_test_case_2();
};
