//!
//! @file 		    Vector.c
//! @author 	    Geoffrey Hunter (gbmhunter@gmail.com)
//! @created	    2014-04-22
//! @last-modified  2014-04-23
//! @brief 		    Contains functions for providing a vector-like object to the C language.
//!

//===============================================================================================//
//================================== HEADER INCLUSIONS ==========================================//
//===============================================================================================//

// System includes
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>		// malloc(), free()
#include <string.h>		// memset(), memcpy()

// User includes
#include "../include/Vector.h"

//===============================================================================================//
//================================== PRECOMPILER CHECKS =========================================//
//===============================================================================================//

// none

//===============================================================================================//
//============================================ DEFINES ==========================================//
//===============================================================================================//

// none

//===============================================================================================//
//======================================== TYPEDEF's ============================================//
//===============================================================================================//

// none

//===============================================================================================//
//=================================== PRIVATE VARIABLES =========================================//
//===============================================================================================//

// none

//===============================================================================================//
//=================================== PRIVATE FUNCTION PROTOTYPES ===============================//
//===============================================================================================//

//! @note       Thread-safe. Not re-entrant.
void Vector_IncreseCapacityIfFull(vector_t *vector);

//===============================================================================================//
//================================== PUBLIC FUNCTIONS ===========================================//
//===============================================================================================//

void Vector_Init(vector_t *vector, uint32_t sizeOfObject, uint32_t growthSize)
{
	#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
		printf("Initialising vector...\r\n");
	#endif

	if(vector == NULL)
	{
		#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
			printf("ERROR: Vector is NULL!\r\n");
		#endif
		return;
	}

    // Initialize sizes and capacity
    vector->size = 0;
    vector->capacity = 0;

    if(growthSize == 0)
    {
		#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
    		printf("ERROR: Growth size to Vector_Init() cannot be 0!\r\n");
		#endif
    	return;
    }
    vector->growthSize = growthSize;
    vector->sizeOfObject = sizeOfObject;

	#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
    	printf("Allocating %u bytes for object array.\r\n", vector->sizeOfObject*vector->growthSize);
	#endif

    // Allocate memory for vector->data
    vector->objectA = malloc(vector->sizeOfObject*vector->growthSize);

    vector->capacity += vector->growthSize;

    if(vector->objectA == NULL)
	{
		#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
			printf("ERROR: malloc() failed!\r\n");
		#endif
		return;
	}

    vector->initComplete = 345;
}

void Vector_Append(vector_t *vector, void* object)
{
	#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
		printf("Appending object to vector...\r\n");
	#endif

	if(vector->initComplete != 345)
	{
		#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
			printf("ERROR: Vector_Append() called before Vector_Init() run!\r\n");
		#endif
		return;
	}

    // Make sure there's room to expand into
    Vector_IncreseCapacityIfFull(vector);

    if(object == NULL)
    {
        // We don't have anything to copy from, so copy nulls
        memset(vector->objectA + vector->size*vector->sizeOfObject, 0x00, vector->sizeOfObject);
    }
    else
    {
        // Copy the object after the last element in the current array
        memcpy(vector->objectA + vector->size*vector->sizeOfObject, object, vector->sizeOfObject);
    }

    // Increment vector->size
    vector->size++;
}

void Vector_Get(vector_t *vector, uint32_t index, void* destination)
{
	if(vector->initComplete != 345)
	{
		#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
			printf("ERROR: Vector_Get() called before Vector_Init() run!\r\n");
		#endif
		return;
	}

    if (index >= vector->size || index < 0)
    {
        //Vector_SendDebugMsg("Index %d out of bounds for vector of size %d.\r\n", index, vector->size);
        return;
    }
    
    // Copy the object in vector to destination    
    memcpy(destination, vector->objectA + index*vector->sizeOfObject, vector->sizeOfObject);
}

void Vector_Set(vector_t *vector, uint32_t index, const void* object)
{
	if(vector->initComplete != 345)
	{
		#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
			printf("ERROR: Vector_Set() called before Vector_Init() run!\r\n");
		#endif
		return;
	}

    // Zero fill the vector up to the desired index
    while(index >= vector->size)
    {
        Vector_Append(vector, NULL);
    }

    // Set the value at the desired index
    memcpy(vector->objectA + index*vector->sizeOfObject, object, vector->sizeOfObject);
}

void Vector_IncreseCapacityIfFull(vector_t *vector)
{
	// Should never be greater than!
    if (vector->size >= vector->capacity)
    {
        // Vector is full
		#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
    		printf("Increasing capacity from %u bytes to %u bytes...\r\n", vector->capacity, vector->capacity + vector->growthSize);
		#endif

        // Resize the allocated memory for the object array
        vector->objectA = realloc(vector->objectA, vector->sizeOfObject*(vector->capacity + vector->growthSize));
        
        if(vector->objectA == NULL)
        {
			#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
        		printf("ERROR: realloc() failed!\r\n");
			#endif

        	return;
        }

		#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
        	printf("Old capacity = %u\r\n", vector->capacity);
		#endif

        // Increase the capacity count by growthSize
        vector->capacity += vector->growthSize;

		#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
        	printf("New capacity = %u\r\n", vector->capacity);
		#endif
    }
}

void Vector_Free(vector_t *vector)
{
	#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
		printf("Vector_Free() called.\r\n");
	#endif

	if(vector->initComplete != 345)
	{
		#if(vectorConfig_ENABLE_DEBUG_CODE == 1)
			printf("ERROR: Vector_Free() called before Vector_Init() run!\r\n");
		#endif
		return;
	}

	if(vector->objectA != NULL)
	{
		// Free the object array (this is the only part of vector which is malloc'ed)
		free(vector->objectA);
	}
}


//===============================================================================================//
//==================================== PRIVATE POWER FUNCTIONS ==================================//
//===============================================================================================//



// EOF
