/*
 * sms_send_request.h
 *
 * The structure to describe a request to send a text message.
 */

#ifndef _sms_send_request_H_
#define _sms_send_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sms_send_request_t sms_send_request_t;




typedef struct sms_send_request_t {
    char *sender_name; // string
    char *body; // string
    char *phone; // string
    char *source; // string

} sms_send_request_t;

sms_send_request_t *sms_send_request_create(
    char *sender_name,
    char *body,
    char *phone,
    char *source
);

void sms_send_request_free(sms_send_request_t *sms_send_request);

sms_send_request_t *sms_send_request_parseFromJSON(cJSON *sms_send_requestJSON);

cJSON *sms_send_request_convertToJSON(sms_send_request_t *sms_send_request);

#endif /* _sms_send_request_H_ */

