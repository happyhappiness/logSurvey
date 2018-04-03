}

/**
 \retval 1	if we have everything needed to complete this request.
 \retval 0	if something is missing.
 */
int
FtpStateData::checkAuth(const HttpHeader * req_hdr)
{
    char *orig_user;
    const char *auth;
    loginParser(request->login, FTP_LOGIN_ESCAPED);

    if (!user[0])
        return 1;		/* no name */

    if (password_url || password[0])
        return 1;		/* passwd provided in URL */

    /* URL has name, but no passwd */
    if (!(auth = req_hdr->getAuth(HDR_AUTHORIZATION, "Basic")))
        return 0;		/* need auth header */

    flags.authenticated = 1;

    orig_user = xstrdup(user);

    loginParser(auth, FTP_LOGIN_NOT_ESCAPED);

    if (strcmp(orig_user, user) == 0) {
        xfree(orig_user);
        return 1;		/* same username */
    }

    xstrncpy(user, orig_user, sizeof(user));
    xfree(orig_user);
    return 0;			/* different username */
}

