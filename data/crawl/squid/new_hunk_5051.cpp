
    if (reply && (strncasecmp(reply, "OK", 2) == 0))
        basic_auth->flags.credentials_ok = 1;
    else {
        basic_auth->flags.credentials_ok = 3;

        if (t && *t)
            r->auth_user_request->setDenyMessage(t);
    }

    basic_auth->credentials_checkedtime = squid_curtime;

    if (cbdataReferenceValidDone(r->data, &cbdata))
