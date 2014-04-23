//!
//! @file 			main.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/04/23
//! @last-modified 	2014/04/23
//! @brief 			Contains main entry point for unit tests.
//! @details
//!					See README.rst in root dir for more info.

#include "CppUTest/TestHarness.h"
#include "CppUTest/TestOutput.h"
#include "CppUTest/TestTestingFixture.h"
#include "CppUTest/CommandLineTestRunner.h"


	
	int main(int ac, char** av)
	{
		return CommandLineTestRunner::RunAllTests(ac, av);
	}

	

