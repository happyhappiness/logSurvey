    return serverConnection;
}

/*
static void
httpStateFree(int fd, void *data)
{
    HttpStateData *httpState = static_cast<HttpStateData *>(data);
    debugs(11, 5, "httpStateFree: FD " << fd << ", httpState=" << data);
    delete httpState;
}*/

void
HttpStateData::httpStateConnClosed(const CommCloseCbParams &params)
{
    debugs(11, 5, "httpStateFree: FD " << params.fd << ", httpState=" << params.data);
    deleteThis("HttpStateData::httpStateConnClosed");
}

int
