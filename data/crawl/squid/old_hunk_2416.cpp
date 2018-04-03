httpStart(FwdState *fwd)
{
    debugs(11, 3, "httpStart: \"" << RequestMethodStr(fwd->request->method) << " " << fwd->entry->url() << "\"" );
    HttpStateData *httpState = new HttpStateData(fwd);

    if (!httpState->sendRequest()) {
        debugs(11, 3, "httpStart: aborted");
        delete httpState;
        return;
    }

