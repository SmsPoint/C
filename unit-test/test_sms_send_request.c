#ifndef sms_send_request_TEST
#define sms_send_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sms_send_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sms_send_request.h"
sms_send_request_t* instantiate_sms_send_request(int include_optional);



sms_send_request_t* instantiate_sms_send_request(int include_optional) {
  sms_send_request_t* sms_send_request = NULL;
  if (include_optional) {
    sms_send_request = sms_send_request_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    sms_send_request = sms_send_request_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return sms_send_request;
}


#ifdef sms_send_request_MAIN

void test_sms_send_request(int include_optional) {
    sms_send_request_t* sms_send_request_1 = instantiate_sms_send_request(include_optional);

	cJSON* jsonsms_send_request_1 = sms_send_request_convertToJSON(sms_send_request_1);
	printf("sms_send_request :\n%s\n", cJSON_Print(jsonsms_send_request_1));
	sms_send_request_t* sms_send_request_2 = sms_send_request_parseFromJSON(jsonsms_send_request_1);
	cJSON* jsonsms_send_request_2 = sms_send_request_convertToJSON(sms_send_request_2);
	printf("repeating sms_send_request:\n%s\n", cJSON_Print(jsonsms_send_request_2));
}

int main() {
  test_sms_send_request(1);
  test_sms_send_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // sms_send_request_MAIN
#endif // sms_send_request_TEST
