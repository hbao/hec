// MyTestSuite.h
#include <cxxtest/TestSuite.h>

class SampleTestSuite : public CxxTest::TestSuite {
public:
	void testAddition(void) {
		TS_ASSERT( 1 + 1 > 1);
		TS_ASSERT_EQUALS( 1 + 1, 2);
	}

	void testMinus(void) {
		TS_ASSERT_EQUALS(2-1, 1);
	}
	
//	void testFailure(void) {
//		TS_ASSERT_EQUALS(1, 0);
//	}
};
