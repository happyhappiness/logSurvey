    return false;
}

/* add the [www-|Proxy-]authenticate header on a 407 or 401 reply */
void
AuthDigestConfig::fixHeader(AuthUserRequest::Pointer auth_user_request, HttpReply *rep, http_hdr_type hdrType, HttpRequest * request)
{
    if (!authenticate)
        return;

    int stale = 0;

    if (auth_user_request != NULL) {
        AuthDigestUserRequest *digest_request;
        digest_request = dynamic_cast<AuthDigestUserRequest*>(auth_user_request.getRaw());
        assert (digest_request != NULL);

        stale = !digest_request->flags.invalid_password;
