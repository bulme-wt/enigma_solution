#include "plugboardtests.h"

// Note: This is equivalent to QTEST_APPLESS_MAIN for multiple test classes.
int main(int argc, char** argv)
{
   int status = 0;
   {
      PlugboardTests tc;
      status |= QTest::qExec(&tc, argc, argv);
   }
   {
//      RotorTests tc;
//      status |= QTest::qExec(&tc, argc, argv);
   }
   return status;
}
