/*
 * sms_send_response.h
 *
 * The structure to describe a response to a text message send request.
 */

#ifndef _sms_send_response_H_
#define _sms_send_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sms_send_response_t sms_send_response_t;




typedef struct sms_send_response_t {
    int success; //boolean
    char *error_message; // string

} sms_send_response_t;

sms_send_response_t *sms_send_response_create(
    int success,
    char *error_message
);

void sms_send_response_free(sms_send_response_t *sms_send_response);

sms_send_response_t *sms_send_response_parseFromJSON(cJSON *sms_send_responseJSON);

cJSON *sms_send_response_convertToJSON(sms_send_response_t *sms_send_response);

#endif /* _sms_send_response_H_ */

