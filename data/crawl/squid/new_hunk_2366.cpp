    /* any other sanity checks that we need in the future */

    /* finally return ok */
    debugs(29, 5, HERE << "Validated. Auth::UserRequest '" << this << "'.");
    return true;
}

void *
Auth::UserRequest::operator new (size_t byteCount)
{
    fatal("Auth::UserRequest not directly allocatable\n");
    return (void *)1;
}

void
Auth::UserRequest::operator delete (void *address)
{
    fatal("Auth::UserRequest child failed to override operator delete\n");
}

Auth::UserRequest::UserRequest():
        _auth_user(NULL),
        message(NULL),
        lastReply(AUTH_ACL_CANNOT_AUTHENTICATE)
{
    debugs(29, 5, HERE << "initialised request " << this);
}

Auth::UserRequest::~UserRequest()
{
    assert(RefCountCount()==0);
    debugs(29, 5, HERE << "freeing request " << this);

    if (user() != NULL) {
        /* release our references to the user credentials */
