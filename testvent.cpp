#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>

#include "vent.hpp"

class TestVentComponents : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(TestVentComponents);
  CPPUNIT_TEST(testVent);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void);
  void tearDown(void);

protected:
  void testVent(void);

private:
  Vent *mVentObj;
};

void TestVentComponents::testVent(void)
{
  mVentObj = new Vent("v_001", "Vent_100", 10, 100);
  CPPUNIT_ASSERT("v_001" == std::get<0>(mVentObj->getVent()));
  CPPUNIT_ASSERT("Vent_100" == std::get<1>(mVentObj->getVent()));
  CPPUNIT_ASSERT(23.04 == std::get<2>(mVentObj->getVent()));
  CPPUNIT_ASSERT(43 == std::get<3>(mVentObj->getVent()));
  CPPUNIT_ASSERT(100 == std::get<4>(mVentObj->getVent()));
  delete mVentObj;

  mVentObj = new Vent("v_002", "Vent_125", 10, 100);
  CPPUNIT_ASSERT("v_002" == std::get<0>(mVentObj->getVent()));
  CPPUNIT_ASSERT("Vent_125" == std::get<1>(mVentObj->getVent()));
  CPPUNIT_ASSERT(29.08 == std::get<2>(mVentObj->getVent()));
  CPPUNIT_ASSERT(34 == std::get<3>(mVentObj->getVent()));
  CPPUNIT_ASSERT(100 == std::get<4>(mVentObj->getVent()));
  delete mVentObj;

  bool expected_exception_thrown = false;
  try {
    mVentObj = new Vent("v_003", "Vent_222", 10, 100);
  } catch (const char *error) {
    expected_exception_thrown = true;
  }

  if (!expected_exception_thrown) {
    CPPUNIT_FAIL("assertion failed");
  }
}

void TestVentComponents::setUp(void)
{
}

void TestVentComponents::tearDown(void)
{
}

CPPUNIT_TEST_SUITE_REGISTRATION(TestVentComponents);

int main(int argc, char* argv[])
{
  CPPUNIT_NS::TestResult testresult;
  CPPUNIT_NS::TestResultCollector collectedresults;
  testresult.addListener (&collectedresults);
  CPPUNIT_NS::BriefTestProgressListener progress;
  testresult.addListener (&progress);
  CPPUNIT_NS::TestRunner testrunner;
  testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
  testrunner.run(testresult);
  CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
  compileroutputter.write();
  std::ofstream xmlFileOut("cppTestResults.xml");
  CppUnit::XmlOutputter xmlOut(&collectedresults, xmlFileOut);
  xmlOut.write();

  return collectedresults.wasSuccessful() ? 0 : 1;
}
