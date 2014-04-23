//!
//! @file 			SizeTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/04/23
//! @last-modified 	2014/04/23
//! @brief 			Tests for making sure the vectors size variable gets calculated correctly.
//! @details
//!					See README.rst in root dir for more info.

#include "CppUTest/TestHarness.h"
#include "CppUTest/TestOutput.h"

// User includes
#include "../include/Vector.h"

namespace VectorTests
{
	TEST_GROUP(SizeTestGroup)
	{

	};

	typedef struct
	{
		bool trueFalse;
		uint32_t aNumber;
	} testStruct_t;

	TEST(SizeTestGroup, InitSizeTest)
	{
		testStruct_t inputStruct;
		inputStruct.trueFalse = true;
		inputStruct.aNumber = 10;
		vector_t myVector;
		Vector_Init(&myVector, sizeof(testStruct_t), 5);

		// Size should be 0
		CHECK_EQUAL(0, myVector.size);

		Vector_Free(&myVector);
	}

	TEST(SizeTestGroup, BasicSizeTest)
	{
		vector_t myVector;
		Vector_Init(&myVector, sizeof(testStruct_t), 5);

		testStruct_t inputStruct;
		inputStruct.trueFalse = true;
		inputStruct.aNumber = 10;

		CHECK_EQUAL(0, myVector.size);

		Vector_Append(&myVector, &inputStruct);

		CHECK_EQUAL(1, myVector.size);

		Vector_Append(&myVector, &inputStruct);

		CHECK_EQUAL(2, myVector.size);

		Vector_Append(&myVector, &inputStruct);

		CHECK_EQUAL(3, myVector.size);

		Vector_Append(&myVector, &inputStruct);

		CHECK_EQUAL(4, myVector.size);

		Vector_Append(&myVector, &inputStruct);

		CHECK_EQUAL(5, myVector.size);

		Vector_Append(&myVector, &inputStruct);

		CHECK_EQUAL(6, myVector.size);

		Vector_Free(&myVector);
	}


} // namespace VectorTests
