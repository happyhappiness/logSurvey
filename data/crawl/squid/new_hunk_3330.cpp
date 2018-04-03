    fatal ("AuthUserRequest child failed to override operator delete\n");
}

AuthUserRequest::AuthUserRequest():
        _auth_user(NULL),
        message(NULL),
        lastReply(AUTH_ACL_CANNOT_AUTHENTICATE)
{
    debugs(29, 5, "AuthUserRequest::AuthUserRequest: initialised request " << this);
}

AuthUserRequest::~AuthUserRequest()
{
    assert(RefCountCount()==0);
    debugs(29, 5, "AuthUserRequest::~AuthUserRequest: freeing request " << this);

    if (user() != NULL) {
        /* release our references to the user credentials */
        user(NULL);
    }

    safe_free(message);
}

void
AuthUserRequest::setDenyMessage(char const *aString)
{
    safe_free(message);
    message = xstrdup(aString);
}

char const *
AuthUserRequest::getDenyMessage()
{
    return message;
}
