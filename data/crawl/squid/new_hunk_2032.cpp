
    assert(basic_auth != NULL);

    if (reply.result == HelperReply::Okay)
        basic_auth->credentials(Auth::Ok);
    else {
        basic_auth->credentials(Auth::Failed);

        if (reply.other().hasContent())
            r->auth_user_request->setDenyMessage(reply.other().content());
    }

    basic_auth->expiretime = squid_curtime;
