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



//===============================================================================================//
//============================================ DEFINES ==========================================//
//===============================================================================================//



//===============================================================================================//
//======================================== TYPEDEF's ============================================//
//===============================================================================================//



//===============================================================================================//
//=================================== PRIVATE VARIABLES =========================================//
//===============================================================================================//




//===============================================================================================//
//=================================== PRIVATE FUNCTION PROTOTYPES ===============================//
//===============================================================================================//

//! @note       Thread-safe. Not re-entrant.
void Vector_IncreseCapacityIfFull(vector_t *vector);

//===============================================================================================//
//================================== PUBLIC FUNCTIONS ===========================================//
//===============================================================================================//


void Vector_Init(vector_t *vector, uint32_t sizeOfObject, uint32_t blockSize)
{
    // Initialize sizes and capacity
    vector->size = 0;
    vector->capacity = blockSize;
    vector->sizeOfObject = sizeOfObject;

    // Allocate memory for vector->data
    vector->objectA = malloc(vector->sizeOfObject*vector->capacity);
}

void Vector_Append(vector_t *vector, void* object)
{
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
    if (index >= vector->size || index < 0)
    {
        Vector_SendDebugMsg("Index %d out of bounds for vector of size %d.\r\n", index, vector->size);
        return;
    }
    
    // Copy the object in vector to destination    
    memcpy(destination, vector->objectA + index*vector->sizeOfObject, vector->sizeOfObject);
}

void Vector_Set(vector_t *vector, uint32_t index, const void* object)
{
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
    if (vector->size >= vector->capacity - 1)
    {
        // Vector is full
        
        // Resize the allocated memory for the object array
        vector->objectA = realloc(vector->objectA, vector->sizeOfObject*(vector->capacity + vector->growthSize));
        
        // Increase the capacity count by growthSize
        vector->capacity += vector->growthSize;
    }
}

void Vector_Free(vector_t *vector)
{
	// Free the object array (this is the only part of vector which is malloc'ed)
    free(vector->objectA);
}


//===============================================================================================//
//==================================== PRIVATE POWER FUNCTIONS ==================================//
//===============================================================================================//



// EOF
