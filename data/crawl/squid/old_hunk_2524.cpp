    }

    /* Special mode to pass the username to the upstream cache */
    if (*orig_request->peer_login == '*') {
        char loginbuf[256];
        const char *username = "-";

        if (orig_request->extacl_user.size())
            username = orig_request->extacl_user.termedBuf();
#if USE_AUTH
        else if (orig_request->auth_user_request != NULL)
            username = orig_request->auth_user_request->username();
#endif

        snprintf(loginbuf, sizeof(loginbuf), "%s%s", username, orig_request->peer_login + 1);

        httpHeaderPutStrf(hdr_out, header, "Basic %s",
                          old_base64_encode(loginbuf));
        return;
    }

    /* external_acl provided credentials */
    if (orig_request->extacl_user.size() && orig_request->extacl_passwd.size() &&
            (strcmp(orig_request->peer_login, "PASS") == 0 ||
             strcmp(orig_request->peer_login, "PROXYPASS") == 0)) {
        char loginbuf[256];
        snprintf(loginbuf, sizeof(loginbuf), SQUIDSTRINGPH ":" SQUIDSTRINGPH,
                 SQUIDSTRINGPRINT(orig_request->extacl_user),
                 SQUIDSTRINGPRINT(orig_request->extacl_passwd));
        httpHeaderPutStrf(hdr_out, header, "Basic %s",
                          old_base64_encode(loginbuf));
        return;
    }

    /* Kerberos login to peer */
#if HAVE_AUTH_MODULE_NEGOTIATE && HAVE_KRB5 && HAVE_GSSAPI
    if (strncmp(orig_request->peer_login, "NEGOTIATE",strlen("NEGOTIATE")) == 0) {
        char *Token=NULL;
        char *PrincipalName=NULL,*p;
        if ((p=strchr(orig_request->peer_login,':')) != NULL ) {
            PrincipalName=++p;
        }
        Token = peer_proxy_negotiate_auth(PrincipalName,request->peer_host);
        if (Token) {
            httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Negotiate %s",Token);
        }
