/**
 * 
* @file "ProtoBuf.c"
* @author Madrick3
* @brief Basic implementation of a Protocol Buffer that is 
* 
* @COMPONENT: ProtoBuf
* @VERSION: 01.00.00
*/
/************************************************************
  Version History
  -----------------------------------------------------------
  Revision |  Author   |  Change ID      |  Description
  01.00.00 |  pflaherty|  --             |  Initial Creation
************************************************************/

/************************************************************
  DEFINES
************************************************************/

/************************************************************
  INCLUDES
************************************************************/
#include "ProtoBuf.h"

/************************************************************
  ENUMS AND TYPEDEFS
************************************************************/

/************************************************************
  LOCAL VARIABLES
************************************************************/

/************************************************************
  GLOBAL FUNCTIONS
************************************************************/
/**
 * Default_Deserialize()
 * Has a very basic implementation - just writes the magic header bytes to the buffer for parsing in test software.
 * Overwriting functions may choose to do the same thing.
 * @param: self - pointer to a Protobuf that is used for
 * 
 * @return length of bytes added to the provided buffer.
 */
uint8 ProtoBuf_Default_Serialize(void * self, uint8 * buffer, uint8 * size)
{
  uint8 length = 0;

  (void)self;
  (void)size;

  buffer[0] = PROTOBUF_HEADER_MAGICBYTE0;
  buffer[1] = PROTOBUF_HEADER_MAGICBYTE1;
  buffer[2] = PROTOBUF_HEADER_MAGICBYTE2;
  buffer[3] = PROTOBUF_HEADER_MAGICBYTE3;

  length = 4; 
  return length;
}

/**
 * Default_Deserialize()
 * Intended to have no implementation, should be overwritten by the calling class/function on creation of the ProtoBuf.
 */
void ProtoBuf_Default_Deserialize(void * self, uint8 * buffer, uint8 * size)
{
  (void)self;
  (void)buffer;
  (void)size;
}

/**
 * Create()
 * Creates a ProtoBuf object and initilizes the default serialize and deserialize function pointers to these ProtoBuf pointers.
 */
Std_ErrorCode ProtoBuf_Create(ProtoBufBase * base)
{
  base->serialize = ProtoBuf_Default_Serialize;
  base->deserialize = ProtoBuf_Default_Deserialize;
  return E_OK;
}

/**
 * Destroy()
 * Destroys protobuffer, removes it from the memory space its been reserved in.
 */
Std_ErrorCode ProtoBuf_Destroy(ProtoBufBase * base)
{
  (void)base;
  return E_OK;
}


/************************************************************
  LOCAL FUNCTIONS
************************************************************/
