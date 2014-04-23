//!
//! @file 		    Vector.h
//! @author 	    Geoffrey Hunter (gbmhunter@gmail.com)
//! @created	    2014-04-22
//! @last-modified  2014-04-23
//! @brief 		    Contains functions for providing a vector-like object to the C language.
//!

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef VECTOR_H
#define VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

//===============================================================================================//
//==================================== PUBLIC DEFINES ===========================================//
//===============================================================================================//



//===============================================================================================//
//====================================== PUBLIC VARIABLES =======================================//
//===============================================================================================//


//! @brief 		The vector type, which holds and indexes objects.
typedef struct 
{
	//! @brief		Used to protect the vector object if it used without Vector_Init() being
	//!				called first.
	uint32_t initComplete;

    //! @brief 		Number of actual objects in array
    uint32_t size;
    
    //! @brief 		The size of a single object (in bytes)
    uint32_t sizeOfObject;
    
    //! @brief		Total number of slots this vector can currently hold
    uint32_t capacity;
    
    //! @brief      Number of objects that the vector allocates for everytime
    //!             it needs to grow its memory (i.e. runs out of room).
    uint32_t growthSize;
    
    //! @brief		Pointer to the array of dynamically-created objects
    void* objectA;
} vector_t;

//! @brief      Initialises a vector object.
//! @param      vector          Pointer to the vector you wish to initialise.
//! @param      sizeOfObject    Size of the object this vector is going to hold.
//! @param      growthSize      Number of objects that the vector allocates for everytime
//!                             it needs to grow its memory (i.e. runs out of room).
//! @note       Thread-safe. Not re-entrant.
void Vector_Init(vector_t *vector, uint32_t sizeOfObject, uint32_t growthSize);

//! @note       Thread-safe. Not re-entrant.
void Vector_Append(vector_t *vector, void* object);

//! @param      vector      Pointer to vector you wish to retrieve an object from.
//! @param      index       The 0-based object number in vector to copy to destination.
//! @param      destination The object to copy to. Make sure that it is the same size
//!                         as the objects stored in the vector, or undefined behaviour
//!                         will result.
//! @note       Thread-safe. Not re-entrant.
void Vector_Get(vector_t *vector, uint32_t index, void* destination);

//! @note       Thread-safe. Not re-entrant.
void Vector_Set(vector_t *vector, uint32_t index, const void* object);

//! @brief      Frees all the memory the vector was using.
//! @note       Thread-safe. Not re-entrant.
void Vector_Free(vector_t *vector);
    
//===============================================================================================//
//=================================== PUBLIC FUNCTION PROTOTYPES ================================//
//===============================================================================================//

#ifdef __cplusplus
}
#endif

#endif VECTOR_H // #ifndef VECTOR_H
    
// EOF
