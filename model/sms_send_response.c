#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sms_send_response.h"



sms_send_response_t *sms_send_response_create(
    int success,
    char *error_message
    ) {
    sms_send_response_t *sms_send_response_local_var = malloc(sizeof(sms_send_response_t));
    if (!sms_send_response_local_var) {
        return NULL;
    }
    sms_send_response_local_var->success = success;
    sms_send_response_local_var->error_message = error_message;

    return sms_send_response_local_var;
}


void sms_send_response_free(sms_send_response_t *sms_send_response) {
    if(NULL == sms_send_response){
        return ;
    }
    listEntry_t *listEntry;
    if (sms_send_response->error_message) {
        free(sms_send_response->error_message);
        sms_send_response->error_message = NULL;
    }
    free(sms_send_response);
}

cJSON *sms_send_response_convertToJSON(sms_send_response_t *sms_send_response) {
    cJSON *item = cJSON_CreateObject();

    // sms_send_response->success
    if(sms_send_response->success) { 
    if(cJSON_AddBoolToObject(item, "success", sms_send_response->success) == NULL) {
    goto fail; //Bool
    }
     } 


    // sms_send_response->error_message
    if(sms_send_response->error_message) { 
    if(cJSON_AddStringToObject(item, "errorMessage", sms_send_response->error_message) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

sms_send_response_t *sms_send_response_parseFromJSON(cJSON *sms_send_responseJSON){

    sms_send_response_t *sms_send_response_local_var = NULL;

    // sms_send_response->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(sms_send_responseJSON, "success");
    if (success) { 
    if(!cJSON_IsBool(success))
    {
    goto end; //Bool
    }
    }

    // sms_send_response->error_message
    cJSON *error_message = cJSON_GetObjectItemCaseSensitive(sms_send_responseJSON, "errorMessage");
    if (error_message) { 
    if(!cJSON_IsString(error_message))
    {
    goto end; //String
    }
    }


    sms_send_response_local_var = sms_send_response_create (
        success ? success->valueint : 0,
        error_message ? strdup(error_message->valuestring) : NULL
        );

    return sms_send_response_local_var;
end:
    return NULL;

}
