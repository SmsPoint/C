#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sms_send_request.h"



sms_send_request_t *sms_send_request_create(
    char *sender_name,
    char *body,
    char *phone,
    char *source
    ) {
    sms_send_request_t *sms_send_request_local_var = malloc(sizeof(sms_send_request_t));
    if (!sms_send_request_local_var) {
        return NULL;
    }
    sms_send_request_local_var->sender_name = sender_name;
    sms_send_request_local_var->body = body;
    sms_send_request_local_var->phone = phone;
    sms_send_request_local_var->source = source;

    return sms_send_request_local_var;
}


void sms_send_request_free(sms_send_request_t *sms_send_request) {
    if(NULL == sms_send_request){
        return ;
    }
    listEntry_t *listEntry;
    if (sms_send_request->sender_name) {
        free(sms_send_request->sender_name);
        sms_send_request->sender_name = NULL;
    }
    if (sms_send_request->body) {
        free(sms_send_request->body);
        sms_send_request->body = NULL;
    }
    if (sms_send_request->phone) {
        free(sms_send_request->phone);
        sms_send_request->phone = NULL;
    }
    if (sms_send_request->source) {
        free(sms_send_request->source);
        sms_send_request->source = NULL;
    }
    free(sms_send_request);
}

cJSON *sms_send_request_convertToJSON(sms_send_request_t *sms_send_request) {
    cJSON *item = cJSON_CreateObject();

    // sms_send_request->sender_name
    if (!sms_send_request->sender_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "senderName", sms_send_request->sender_name) == NULL) {
    goto fail; //String
    }


    // sms_send_request->body
    if (!sms_send_request->body) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "body", sms_send_request->body) == NULL) {
    goto fail; //String
    }


    // sms_send_request->phone
    if (!sms_send_request->phone) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "phone", sms_send_request->phone) == NULL) {
    goto fail; //String
    }


    // sms_send_request->source
    if (!sms_send_request->source) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "source", sms_send_request->source) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

sms_send_request_t *sms_send_request_parseFromJSON(cJSON *sms_send_requestJSON){

    sms_send_request_t *sms_send_request_local_var = NULL;

    // sms_send_request->sender_name
    cJSON *sender_name = cJSON_GetObjectItemCaseSensitive(sms_send_requestJSON, "senderName");
    if (!sender_name) {
        goto end;
    }

    
    if(!cJSON_IsString(sender_name))
    {
    goto end; //String
    }

    // sms_send_request->body
    cJSON *body = cJSON_GetObjectItemCaseSensitive(sms_send_requestJSON, "body");
    if (!body) {
        goto end;
    }

    
    if(!cJSON_IsString(body))
    {
    goto end; //String
    }

    // sms_send_request->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(sms_send_requestJSON, "phone");
    if (!phone) {
        goto end;
    }

    
    if(!cJSON_IsString(phone))
    {
    goto end; //String
    }

    // sms_send_request->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(sms_send_requestJSON, "source");
    if (!source) {
        goto end;
    }

    
    if(!cJSON_IsString(source))
    {
    goto end; //String
    }


    sms_send_request_local_var = sms_send_request_create (
        strdup(sender_name->valuestring),
        strdup(body->valuestring),
        strdup(phone->valuestring),
        strdup(source->valuestring)
        );

    return sms_send_request_local_var;
end:
    return NULL;

}
