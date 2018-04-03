 * they allow the user access. Password syncronisation is not tackled
 * by digest - just preventing on the wire compromise.
 *
 * Copyright (c) 2003  Robert Collins  <robertc@squid-cache.org>
 */

#include "digest_common.h"
#include "text_backend.h"

static void
ParseBuffer(char *buf, RequestData *requestData)
{
    char *p;
    requestData->parsed = 0;
    if ((p = strchr(buf, '\n')) != NULL)
	*p = '\0';		/* strip \n */
    if ((requestData->user = strtok(buf, "\"")) == NULL)
	return;
    if ((requestData->realm = strtok(NULL, "\"")) == NULL)
	return;
    if ((requestData->realm = strtok(NULL, "\"")) == NULL)
	return;
    requestData->parsed = -1;
}

static void
OutputHHA1(RequestData *requestData)
{
    requestData->error = 0;
    GetHHA1(requestData);
    if (requestData->error) {    
	printf("ERR\n");
	return;
    }
    printf("%s\n", requestData->HHA1);
}

static void
DoOneRequest(char *buf)
{
    RequestData requestData;
    ParseBuffer (buf, &requestData);
    if (!requestData.parsed) {
	printf ("ERR\n");
	return;
    }
    OutputHHA1(&requestData);
}

int
main(int argc, char **argv)
{
    char buf[256];
    setbuf(stdout, NULL);
    ProcessArguments (argc, argv);
    while (fgets(buf, 256, stdin) != NULL)
	DoOneRequest (buf);
    exit(0);
}
