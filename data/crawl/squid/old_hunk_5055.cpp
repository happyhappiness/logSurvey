    assert(digest_request);
    digest_user = dynamic_cast < digest_user_h * >(auth_user_request->user());

    if (reply && (strncasecmp(reply, "ERR", 3) == 0))
        digest_request->credentials(AuthDigestUserRequest::Failed);
    else if (reply) {
        CvtBin(reply, digest_user->HA1);
        digest_user->HA1created = 1;
    }
