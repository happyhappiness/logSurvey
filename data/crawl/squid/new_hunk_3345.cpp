    helperStatefulStats(sentry, ntlmauthenticators, "NTLM Authenticator Statistics");
}

/*
 * Decode a NTLM [Proxy-]Auth string, placing the results in the passed
 * Auth_user structure.
 */
AuthUserRequest::Pointer
AuthNTLMConfig::decode(char const *proxy_auth)
{
    NTLMUser *newUser = new NTLMUser(AuthConfig::Find("ntlm"));
    AuthUserRequest::Pointer auth_user_request = new AuthNTLMUserRequest();
    assert(auth_user_request->user() == NULL);

    auth_user_request->user(newUser);
    auth_user_request->user()->auth_type = AUTH_NTLM;

    /* all we have to do is identify that it's NTLM - the helper does the rest */
    debugs(29, 9, "AuthNTLMConfig::decode: NTLM authentication");
    return auth_user_request;
}

void
NTLMUser::deleteSelf() const
{
