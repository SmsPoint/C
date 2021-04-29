#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/sms_send_request.h"
#include "../model/sms_send_response.h"


// Send a text message request.
//
sms_send_response_t*
DefaultAPI_smsSend(apiClient_t *apiClient, sms_send_request_t * sms_send_request );


