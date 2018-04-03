    debugs(29, 2, "authenticateAuthUserAddIp: user '" << username() << "' has been seen at a new IP address (" << ipaddr << ")");
}


void
AuthUser::lock()
{
    debugs(29, 9, "authenticateAuthUserLock auth_user '" << this << "'.");
    assert(this != NULL);
    references++;
    debugs(29, 9, "authenticateAuthUserLock auth_user '" << this << "' now at '" << references << "'.");
}

void
AuthUser::unlock()
{
    debugs(29, 9, "authenticateAuthUserUnlock auth_user '" << this << "'.");
    assert(this != NULL);

    if (references > 0) {
        references--;
    } else {
        debugs(29, 1, "Attempt to lower Auth User " << this << " refcount below 0!");
    }

    debugs(29, 9, "authenticateAuthUserUnlock auth_user '" << this << "' now at '" << references << "'.");

    if (references == 0)
        delete this;
}

/* addToNameCache: add a auth_user structure to the username cache */
void
AuthUser::addToNameCache()
{
    usernamehash = new AuthUserHashPointer (this);
}
