//!
//! @file 			GrowthTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/04/23
//! @last-modified 	2014/04/23
//! @brief 			Tests that the vector grows correctly.
//! @details
//!					See README.rst in root dir for more info.

#include "CppUTest/TestHarness.h"
#include "CppUTest/TestOutput.h"

#include "../include/Vector.h"


namespace VectorTests
{
	TEST_GROUP(GrowthTestGroup)
	{

	};

	typedef struct
	{
		bool trueFalse;
		uint32_t aNumber;
	} testStruct_t;

	TEST(GrowthTestGroup, ZeroGrowthTest)
	{
		testStruct_t inputStruct;
		inputStruct.trueFalse = true;
		inputStruct.aNumber = 10;
		vector_t myVector;
		Vector_Init(&myVector, sizeof(testStruct_t), 0);
		Vector_Append(&myVector, &inputStruct);
		Vector_Free(&myVector);
		// If program gets to here we are doing fine!
	}

	TEST(GrowthTestGroup, OneElementTest)
	{
		testStruct_t inputStruct;
		inputStruct.trueFalse = true;
		inputStruct.aNumber = 10;
		vector_t myVector;
		Vector_Init(&myVector, sizeof(testStruct_t), 5);
		Vector_Append(&myVector, &inputStruct);

		testStruct_t outputStruct;
		Vector_Get(&myVector, 0, &outputStruct);

		CHECK_EQUAL(true, outputStruct.trueFalse);
		CHECK_EQUAL(10, outputStruct.aNumber);

		Vector_Free(&myVector);
	}

	TEST(GrowthTestGroup, InitGrowthTest)
	{
		vector_t myVector;
		Vector_Init(&myVector, sizeof(testStruct_t), 5);

		// Total size of vector should now be 5
		CHECK_EQUAL(5, myVector.capacity);

		Vector_Free(&myVector);
	}

	TEST(GrowthTestGroup, FirstGrowthTest)
	{
		vector_t myVector;
		Vector_Init(&myVector, sizeof(testStruct_t), 5);

		// Total capacity of vector should be 0
		CHECK_EQUAL(5, myVector.capacity);

		testStruct_t inputStruct;
		inputStruct.trueFalse = true;
		inputStruct.aNumber = 10;

		Vector_Append(&myVector, &inputStruct);

		// Total capacity of vector should now be 5
		CHECK_EQUAL(5, myVector.capacity);

		Vector_Append(&myVector, &inputStruct);
		Vector_Append(&myVector, &inputStruct);
		Vector_Append(&myVector, &inputStruct);
		Vector_Append(&myVector, &inputStruct);

		// Total size of vector should still be 5
		CHECK_EQUAL(5, myVector.capacity);

		Vector_Append(&myVector, &inputStruct);

		// Total size of vector should now be 10
		CHECK_EQUAL(10, myVector.capacity);

		Vector_Free(&myVector);
	}

} // namespace VectorTests
