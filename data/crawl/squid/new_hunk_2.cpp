        acl_checklist->al->request = request;
        HTTPMSGLOCK(acl_checklist->al->request);
        acl_checklist->nonBlockingCheck(httpsSslBumpAccessCheckDone, this);
#else
        fatal("FATAL: SSL-Bump requires --with-openssl");
#endif
        return;
    } else {
        httpsEstablish(this, port->secure.staticContext);
    }
}

#if USE_OPENSSL
void
ConnStateData::sslCrtdHandleReplyWrapper(void *data, const Helper::Reply &reply)
{
