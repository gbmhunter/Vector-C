//!
//! @file 			MemoryLEakTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/04/23
//! @last-modified 	2014/04/23
//! @brief 			Tests that the vector manages memory correctly.
//! @details
//!					See README.rst in root dir for more info.

#include "CppUTest/TestHarness.h"
#include "CppUTest/TestOutput.h"

#include "../include/Vector.h"


namespace VectorTests
{
	TEST_GROUP(MemoryLeakTestGroup)
	{

	};

	typedef struct
	{
		bool trueFalse;
		uint32_t aNumber;
	} testStruct_t;

	TEST(MemoryLeakTestGroup, SimpleMemoryLeakTest)
	{
		testStruct_t inputStruct;
		vector_t myVector;
		Vector_Init(&myVector, sizeof(testStruct_t), 5);
		Vector_Append(&myVector, &inputStruct);
		Vector_Free(&myVector);
		// If memory leak occurs, this will be picked up by cpputest upon exit of this test
	}

	TEST(MemoryLeakTestGroup, ComplexMemoryLeakTest)
	{
		testStruct_t inputStruct;
		vector_t myVector;
		Vector_Init(&myVector, sizeof(testStruct_t), 5);

		// Create a large vector
		uint32_t x;
		for(x = 0; x < 10000; x++)
		{
			Vector_Append(&myVector, &inputStruct);
		}

		Vector_Free(&myVector);
		// If memory leak occurs, this will be picked up by cpputest upon exit of this test
	}

} // namespace VectorTests
