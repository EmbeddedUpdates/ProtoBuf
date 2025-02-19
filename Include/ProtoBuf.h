/**
 * 
* @file "Protobuf.h"
* @author Madrick3
* @brief A protocol agnostic data buffer for various project .
* 
* @COMPONENT: PROTOBUF
* @VERSION: 01.00.00
*/
/************************************************************
  Version History
  -----------------------------------------------------------
  Revision |  Author   |  Change ID  |  Description
  01.00.00 |  Madrick3 |  Skeleton   |  Initial Creation
************************************************************/

#ifndef PROTOBUF_H
#define PROTOBUF_H

/************************************************************
  DEFINES
************************************************************/
/* number of bytes in a payload, at maximum */
/* #define PROTOBUF_BUFFER_MAXSIZE 64 */

/* PROTOBUF == 940708DF */
#define PROTOBUF_HEADER_MAGICBYTE0 0x94
#define PROTOBUF_HEADER_MAGICBYTE1 0x07
#define PROTOBUF_HEADER_MAGICBYTE2 0x08
#define PROTOBUF_HEADER_MAGICBYTE3 0xDF

/************************************************************
  INCLUDES
************************************************************/
/* Only dependency - to track std_responsecodes in c programming projects */
#include "Platform_Types.h"
/************************************************************
  ENUMS AND TYPEDEFS
************************************************************/
/* typedef for handles/ids to buffers */
typedef uint8 ProtoBufHandle;

/* public interface for the individual protobuf, using function pointers?*/
typedef struct ProtoBufBase_tag
{
  uint8 (*serialize)(void * self, uint8 * buffer, uint8 * size);
  void (*deserialize)(void * self, uint8 * buffer, uint8 * size);
} ProtoBufBase;

/************************************************************
  EXTERN FUNCTIONS
************************************************************/

/************************************************************
   DEFAULT CLASS FUNCTIONS
************************************************************/
uint8 ProtoBuf_Default_Serialize(void * self, uint8 * buffer, uint8 * size);
void ProtoBuf_Default_Deserialize(void * self, uint8 * buffer, uint8 * size);

/************************************************************
  GLOBAL FUNCTIONS
************************************************************/
extern Std_ErrorCode ProtoBuf_Create(ProtoBufBase * base);
extern Std_ErrorCode ProtoBuf_Destroy(ProtoBufBase * base);

#endif /* PROTOBUF_H */