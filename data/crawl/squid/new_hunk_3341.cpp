    helperStatefulStats(sentry, negotiateauthenticators, "Negotiate Authenticator Statistics");
}

/*
 * Decode a Negotiate [Proxy-]Auth string, placing the results in the passed
 * Auth_user structure.
 */
AuthUserRequest::Pointer
AuthNegotiateConfig::decode(char const *proxy_auth)
{
    NegotiateUser *newUser = new NegotiateUser(&negotiateConfig);
    AuthUserRequest *auth_user_request = new AuthNegotiateUserRequest();
    assert(auth_user_request->user() == NULL);

    auth_user_request->user(newUser);
    auth_user_request->user()->auth_type = AUTH_NEGOTIATE;

    /* all we have to do is identify that it's Negotiate - the helper does the rest */
    debugs(29, 9, "AuthNegotiateConfig::decode: Negotiate authentication");
    return auth_user_request;
}

void
NegotiateUser::deleteSelf() const
{
    delete this;
}

NegotiateUser::NegotiateUser(AuthConfig *aConfig) : AuthUser (aConfig)
{
    proxy_auth_list.head = proxy_auth_list.tail = NULL;
}
