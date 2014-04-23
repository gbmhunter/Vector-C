//!
//! @file 			GetSetTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/04/23
//! @last-modified 	2014/04/23
//! @brief 			Contains get/set (read/write) tests.
//! @details
//!					See README.rst in root dir for more info.

#include "CppUTest/TestHarness.h"
#include "CppUTest/TestOutput.h"

// User includes
#include "../include/Vector.h"

namespace VectorTests
{
	TEST_GROUP(GetSetTestGroup)
	{

	};

	typedef struct
	{
		bool trueFalse;
		uint32_t aNumber;
	} testStruct_t;

	TEST(GetSetTestGroup, OneElementGetSetTest)
	{
		testStruct_t inputStruct;
		inputStruct.trueFalse = true;
		inputStruct.aNumber = 10;
		vector_t myVector;
		Vector_Init(&myVector, sizeof(testStruct_t), 5);
		Vector_Append(&myVector, &inputStruct);

		testStruct_t outputStruct;
		Vector_Get(&myVector, 0, &outputStruct);

		CHECK_EQUAL(outputStruct.trueFalse, true);
		CHECK_EQUAL(outputStruct.aNumber, 10);

		Vector_Free(&myVector);

	}

	TEST(GetSetTestGroup, TwoElementGetSetTest)
	{
		testStruct_t inputStruct1;
		inputStruct1.trueFalse = true;
		inputStruct1.aNumber = 10;

		testStruct_t inputStruct2;
		inputStruct2.trueFalse = false;
		inputStruct2.aNumber = 76;

		// Create and init vector
		vector_t myVector;
		Vector_Init(&myVector, sizeof(testStruct_t), 1);

		// Add objects to vector
		Vector_Append(&myVector, &inputStruct1);
		Vector_Append(&myVector, &inputStruct2);

		testStruct_t outputStruct;

		// Check element 1
		Vector_Get(&myVector, 0, &outputStruct);
		CHECK_EQUAL(outputStruct.trueFalse, true);
		CHECK_EQUAL(outputStruct.aNumber, 10);

		// Check element 2
		Vector_Get(&myVector, 1, &outputStruct);
		CHECK_EQUAL(outputStruct.trueFalse, false);
		CHECK_EQUAL(outputStruct.aNumber, 76);

		Vector_Free(&myVector);
	}

} // namespace VectorTests
