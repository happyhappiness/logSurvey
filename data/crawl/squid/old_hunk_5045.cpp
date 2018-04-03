    requestData->error = 0;
    GetHHA1(requestData);
    if (requestData->error) {    
	printf("ERR\n");
	return;
    }
    printf("%s\n", requestData->HHA1);