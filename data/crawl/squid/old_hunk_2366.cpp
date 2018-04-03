    /* any other sanity checks that we need in the future */

    /* finally return ok */
    debugs(29, 5, HERE << "Validated. AuthUserRequest '" << this << "'.");
    return true;
}

void *
AuthUserRequest::operator new (size_t byteCount)
{
    fatal ("AuthUserRequest not directly allocatable\n");
    return (void *)1;
}

void
AuthUserRequest::operator delete (void *address)
{
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
