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
void ProtoBuf_Default_Serialize(void * self, uint8 * buffer, uint8 * size)
{
  (void)self;
  (void)size;

  buffer[0] = PROTOBUF_HEADER_MAGICBYTE0;
  buffer[1] = PROTOBUF_HEADER_MAGICBYTE1;
  buffer[2] = PROTOBUF_HEADER_MAGICBYTE2;
  buffer[3] = PROTOBUF_HEADER_MAGICBYTE3;

}

void ProtoBuf_Default_Deserialize(void * self, uint8 * buffer, uint8 * size)
{
  (void)self;
  (void)buffer;
  (void)size;
}

Std_ErrorCode ProtoBuf_Create(ProtoBufBase * base)
{
  base->serialize = ProtoBuf_Default_Serialize;
  base->deserialize = ProtoBuf_Default_Deserialize;
  return E_OK;
}

Std_ErrorCode ProtoBuf_Destroy(ProtoBufBase * base)
{
  (void)base;
  return E_OK;
}


/************************************************************
  LOCAL FUNCTIONS
************************************************************/
