{
    requestData->error = 0;
    GetHHA1(requestData);
    if (requestData->error) {
        SEND_ERR("message=\"No such user\"");
        return;
