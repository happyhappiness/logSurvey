}

void
ServerStateData::sendCommand()
{
    if (!fwd->request->header.has(HDR_FTP_COMMAND)) {
        abortTransaction("Internal error: FTP gateway request with no command");
