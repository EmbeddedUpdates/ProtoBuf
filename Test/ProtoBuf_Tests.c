/* =========================================================================
    Unity - A Test Framework for C
    ThrowTheSwitch.org
    Copyright (c) 2007-24 Mike Karlesky, Mark VanderVoord, & Greg Williams
    SPDX-License-Identifier: MIT
========================================================================= */


/* #include "Timer_RP2040.h" */
#include "ProtoBuf_Test.h"
#include "unity.h"

#pragma ab

void setUp(void)
{
}

/* 
  These are run after each test, so we want to make sure the global variable is 'UNINIT' 
  so that each test can behave as if its its own test. 
*/
void tearDown(void)
{

}

/* HELPER FUNCTIONS */

/* TESTS */
/* Calls ...Create() and returns Ok */
void test_ProtoBuf_Create_ReturnsOk(void)
{
  Std_ErrorCode retVal = E_NOT_OK;
  ProtoBufBase newProtoBuf;
  retVal = ProtoBuf_Create(&newProtoBuf);
  TEST_ASSERT_EQUAL(E_OK, retVal);
}

void test_ProtoBuf_Create_serializeIsDefault(void)
{
  Std_ErrorCode retVal = E_NOT_OK;
  ProtoBufBase newProtoBuf;
  retVal = ProtoBuf_Create(&newProtoBuf);
  TEST_ASSERT_EQUAL(newProtoBuf.serialize, ProtoBuf_Default_Serialize);
  (void) retVal;
}

void test_ProtoBuf_Create_DeserializeIsDefault(void)
{
  Std_ErrorCode retVal = E_NOT_OK;
  ProtoBufBase newProtoBuf;
  retVal = ProtoBuf_Create(&newProtoBuf);
  TEST_ASSERT_EQUAL(newProtoBuf.deserialize, ProtoBuf_Default_Deserialize);
  (void) retVal;
}

/* Calls ...Destroy() and returns OK*/
void test_ProtoBuf_Destroy_ReturnsOk(void)
{
  Std_ErrorCode retVal = E_NOT_OK;
  ProtoBufBase newProtoBuf;
  retVal = ProtoBuf_Destroy(&newProtoBuf);
  TEST_ASSERT_EQUAL(E_OK, retVal);
}

void test_ProtoBuf_Serialize_ExpectedOutput(void)
{
  Std_ErrorCode retVal = E_NOT_OK;
  ProtoBufBase newProtoBuf;
  uint8 buff[64] = {0};
  uint8 size = 0;

  uint8 expectedresult[4] = {0x94, 0x07, 0x08, 0xDF};
  retVal = ProtoBuf_Create(&newProtoBuf);
  newProtoBuf.serialize(&newProtoBuf, buff, &size);
  
  TEST_ASSERT_EQUAL_CHAR_ARRAY(expectedresult, buff, 4);
  (void) retVal;
}

