#ifndef sms_send_response_TEST
#define sms_send_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sms_send_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sms_send_response.h"
sms_send_response_t* instantiate_sms_send_response(int include_optional);



sms_send_response_t* instantiate_sms_send_response(int include_optional) {
  sms_send_response_t* sms_send_response = NULL;
  if (include_optional) {
    sms_send_response = sms_send_response_create(
      1,
      "0"
    );
  } else {
    sms_send_response = sms_send_response_create(
      1,
      "0"
    );
  }

  return sms_send_response;
}


#ifdef sms_send_response_MAIN

void test_sms_send_response(int include_optional) {
    sms_send_response_t* sms_send_response_1 = instantiate_sms_send_response(include_optional);

	cJSON* jsonsms_send_response_1 = sms_send_response_convertToJSON(sms_send_response_1);
	printf("sms_send_response :\n%s\n", cJSON_Print(jsonsms_send_response_1));
	sms_send_response_t* sms_send_response_2 = sms_send_response_parseFromJSON(jsonsms_send_response_1);
	cJSON* jsonsms_send_response_2 = sms_send_response_convertToJSON(sms_send_response_2);
	printf("repeating sms_send_response:\n%s\n", cJSON_Print(jsonsms_send_response_2));
}

int main() {
  test_sms_send_response(1);
  test_sms_send_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // sms_send_response_MAIN
#endif // sms_send_response_TEST
