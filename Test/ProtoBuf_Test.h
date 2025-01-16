#include "ProtoBuf.h"

/************************************************************
  LOCAL VARIABLES
************************************************************/


/************************************************************
  LOCAL FUNCTIONS
************************************************************/
/* INIT */
extern void test_ProtoBuf_Create_ReturnsOk(void);
extern void test_ProtoBuf_Destroy_ReturnsOk(void);

/* Confirming the default func ptr members */
extern void test_ProtoBuf_Create_serializeIsDefault(void);
extern void test_ProtoBuf_Create_DeserializeIsDefault(void);

/* we should test the default implementations of serialize*/
extern void test_ProtoBuf_Serialize_ExpectedOutput(void);
