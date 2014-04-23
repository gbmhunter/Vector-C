//!
//! @file 			BasicTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/04/23
//! @last-modified 	2014/04/23
//! @brief 			Contains basic tests.
//! @details
//!					See README.rst in root dir for more info.

#include "CppUTest/TestHarness.h"
#include "CppUTest/TestOutput.h"

namespace VectorTests
{
	TEST_GROUP(FirstTestGroup)
	{

	};

	TEST(FirstTestGroup, FirstTest)
	{
		CHECK(true);
	}

} // namespace VectorTests
