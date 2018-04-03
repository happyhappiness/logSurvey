            username = request->auth_user_request->username();
#endif

        snprintf(loginbuf, sizeof(loginbuf), "%s%s", username, request->peer_login + 1);

        httpHeaderPutStrf(hdr_out, header, "Basic %s",
                          old_base64_encode(loginbuf));
        return;
    }

    /* external_acl provided credentials */
    if (request->extacl_user.size() && request->extacl_passwd.size() &&
            (strcmp(request->peer_login, "PASS") == 0 ||
             strcmp(request->peer_login, "PROXYPASS") == 0)) {
        char loginbuf[256];
        snprintf(loginbuf, sizeof(loginbuf), SQUIDSTRINGPH ":" SQUIDSTRINGPH,
                 SQUIDSTRINGPRINT(request->extacl_user),
                 SQUIDSTRINGPRINT(request->extacl_passwd));
        httpHeaderPutStrf(hdr_out, header, "Basic %s",
                          old_base64_encode(loginbuf));
        return;
    }
    // if no external user credentials are available to fake authentication with PASS acts like PASSTHRU
