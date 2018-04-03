    assert(replyData->auth_user_request != NULL);
    Auth::UserRequest::Pointer auth_user_request = replyData->auth_user_request;

    switch (reply.result) {
    case HelperReply::Error: {
        /* allow this because the digest_request pointer is purely local */
        Auth::Digest::UserRequest *digest_request = dynamic_cast<Auth::Digest::UserRequest *>(auth_user_request.getRaw());
        assert(digest_request);

        digest_request->user()->credentials(Auth::Failed);
        digest_request->flags.invalid_password = 1;

        if (reply.other().hasContent())
            digest_request->setDenyMessage(reply.other().content());
    }
    break;

    case HelperReply::Unknown: // Squid 3.2 and older the digest helper only returns a HA1 hash (no "OK")
    case HelperReply::Okay: {
        /* allow this because the digest_request pointer is purely local */
        Auth::Digest::User *digest_user = dynamic_cast<Auth::Digest::User *>(auth_user_request->user().getRaw());
        assert(digest_user != NULL);

        CvtBin(reply.other().content(), digest_user->HA1);
        digest_user->HA1created = 1;
    }
    break;

    default:
        ; // XXX: handle other states properly.
    }

    void *cbdata = NULL;
