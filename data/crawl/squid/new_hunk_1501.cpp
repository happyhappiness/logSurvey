{
    requestData->error = 0;
    GetHHA1(requestData);
    if (requestData->channelId >= 0)
        printf("%u ", requestData->channelId);
    if (requestData->error) {
        SEND_ERR("message=\"No such user\"");
        return;
