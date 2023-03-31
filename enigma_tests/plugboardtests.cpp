#include "plugboardtests.h"

#include "../plugboard.h"
#include "../enigmaexception.h"

// add necessary includes here

PlugboardTests::PlugboardTests()
{

}

PlugboardTests::~PlugboardTests()
{

}

void PlugboardTests::plugboard_test_case0()
{
    PlugBoard pb = {{{}}};
    QVERIFY(pb.encrypt('A') == 'A');
    QVERIFY(pb.encrypt('B') == 'B');
    QVERIFY(pb.encrypt('C') == 'C');


    QVERIFY(pb.encrypt('X') == 'X');
    QVERIFY(pb.encrypt('Y') == 'Y');
    QVERIFY(pb.encrypt('Z') == 'Z');
}

void PlugboardTests::plugboard_test_case1()
{
    PlugBoard pb = {{{'A', 'B'}}};
    QCOMPARE(pb.encrypt('A'), 'B');
    QCOMPARE(pb.encrypt('B'), 'A');
    QCOMPARE(pb.encrypt('C'), 'C');

    QCOMPARE(pb.encrypt('X'), 'X');
    QCOMPARE(pb.encrypt('Y'), 'Y');
    QCOMPARE(pb.encrypt('Z'), 'Z');
}

void PlugboardTests::plugboard_test_case2()
{
    PlugBoard pb = {{{'A', 'Y'}, {'B', 'X'}, {'C', 'G'}}};
    QCOMPARE(pb.encrypt('A'), 'Y');
    QCOMPARE(pb.encrypt('B'), 'X');
    QCOMPARE(pb.encrypt('C'), 'G');

    QCOMPARE_EQ(pb.encrypt('X'), 'B');
    QCOMPARE(pb.encrypt('Y'), 'A');
    QCOMPARE(pb.encrypt('G'), 'C');
}

void PlugboardTests::plugboard_plug_cable_test_case_1()
{
    PlugBoard pb = {{}};
    QCOMPARE(pb.encrypt('A'), 'A');
    QCOMPARE(pb.encrypt('B'), 'B');
    QCOMPARE(pb.encrypt('C'), 'C');

    QCOMPARE_EQ(pb.encrypt('X'), 'X');
    QCOMPARE(pb.encrypt('Y'), 'Y');
    QCOMPARE(pb.encrypt('Z'), 'Z');

    pb.plugCable('A', 'B');

    QCOMPARE(pb.encrypt('A'), 'B');
    QCOMPARE(pb.encrypt('B'), 'A');
    QCOMPARE(pb.encrypt('C'), 'C');

    QCOMPARE_EQ(pb.encrypt('X'), 'X');
    QCOMPARE(pb.encrypt('Y'), 'Y');
    QCOMPARE(pb.encrypt('Z'), 'Z');
}


void PlugboardTests::plugboard_plug_cable_test_case_2()
{
    PlugBoard pb = {{{'A', 'C'}}};
    QCOMPARE(pb.encrypt('A'), 'C');
    QCOMPARE(pb.encrypt('B'), 'B');
    QCOMPARE(pb.encrypt('C'), 'A');

    QCOMPARE_EQ(pb.encrypt('X'), 'X');
    QCOMPARE(pb.encrypt('Y'), 'Y');
    QCOMPARE(pb.encrypt('Z'), 'Z');

    QVERIFY_THROWS_EXCEPTION(EnigmaException, pb.plugCable('A', 'B'));

    QCOMPARE(pb.encrypt('A'), 'C');
    QCOMPARE(pb.encrypt('B'), 'B');
    QCOMPARE(pb.encrypt('C'), 'A');

    QCOMPARE_EQ(pb.encrypt('X'), 'X');
    QCOMPARE(pb.encrypt('Y'), 'Y');
    QCOMPARE(pb.encrypt('Z'), 'Z');
}


//#include "tst_enigmatests.moc"
