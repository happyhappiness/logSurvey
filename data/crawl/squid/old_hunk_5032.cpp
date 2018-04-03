
#include "digest_common.h"
#include "text_backend.h"

static void
ParseBuffer(char *buf, RequestData *requestData)
{
    char *p;
    requestData->parsed = 0;
