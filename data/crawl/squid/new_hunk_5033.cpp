}

static void
OutputHHA1(RequestData * requestData)
{
    requestData->error = 0;
    GetHHA1(requestData);
    if (requestData->error) {
	printf("ERR No such user\n");
	return;
    }