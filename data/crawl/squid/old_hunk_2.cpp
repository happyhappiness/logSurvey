        acl_checklist->al->request = request;
        HTTPMSGLOCK(acl_checklist->al->request);
        acl_checklist->nonBlockingCheck(httpsSslBumpAccessCheckDone, this);
        return;
    } else {
        httpsEstablish(this, port->secure.staticContext);
    }
}

void
ConnStateData::sslCrtdHandleReplyWrapper(void *data, const Helper::Reply &reply)
{
