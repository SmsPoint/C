#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "DefaultAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// Send a text message request.
//
sms_send_response_t*
DefaultAPI_smsSend(apiClient_t *apiClient, sms_send_request_t * sms_send_request )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/sms/send")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/sms/send");




    // Body Param
    cJSON *localVarSingleItemJSON_sms_send_request = NULL;
    if (sms_send_request != NULL)
    {
        //string
        localVarSingleItemJSON_sms_send_request = sms_send_request_convertToJSON(sms_send_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_sms_send_request);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 0) {
        printf("%s\n","A response to a text message send request.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    sms_send_response_t *elementToReturn = sms_send_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_sms_send_request) {
        cJSON_Delete(localVarSingleItemJSON_sms_send_request);
        localVarSingleItemJSON_sms_send_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

