#include "text_backend.h"
#define PROGRAM_NAME "digest_pw_auth"

static void
GetHHA1(RequestData * requestData)
{
    TextHHA1(requestData);
