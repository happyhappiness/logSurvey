    fatal ("AuthUserRequest child failed to override operator delete\n");
}

AuthUserRequest::AuthUserRequest():_auth_user(NULL), message(NULL),
        references (0), lastReply (AUTH_ACL_CANNOT_AUTHENTICATE)
{
    debugs(29, 5, "AuthUserRequest::AuthUserRequest: initialised request " <<
           this);
}

AuthUserRequest::~AuthUserRequest()
{
    dlink_node *link;
    debugs(29, 5, "AuthUserRequest::~AuthUserRequest: freeing request " <<
           this);
    assert(references == 0);

    if (user()) {
        /* unlink from the auth_user struct */
        link = user()->requests.head;

        while (link && (link->data != this))
            link = link->next;

        assert(link != NULL);

        dlinkDelete(link, &user()->requests);

        dlinkNodeDelete(link);

        /* unlock the request structure's lock */
        user()->unlock();

        user(NULL);
    }

    safe_free (message);
}

void
AuthUserRequest::setDenyMessage (char const *aString)
{
    safe_free (message);
    message = xstrdup (aString);
}

char const *
AuthUserRequest::getDenyMessage ()
{
    return message;
}