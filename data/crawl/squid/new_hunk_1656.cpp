    debugs(29, 2, HERE << "user '" << username() << "' has been seen at a new IP address (" << ipaddr << ")");
}

SBuf
Auth::User::BuildUserKey(const char *username, const char *realm)
{
    SBuf key;
    key.Printf("%s:%s", username, realm);
    return key;
}

/**
 * Add the Auth::User structure to the username cache.
 */
