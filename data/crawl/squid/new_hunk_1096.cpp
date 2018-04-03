            username = request->auth_user_request->username();
#endif

        blen = base64_encode_update(&ctx, loginbuf, strlen(username), reinterpret_cast<const uint8_t*>(username));
        blen += base64_encode_update(&ctx, loginbuf+blen, strlen(request->peer_login +1), reinterpret_cast<const uint8_t*>(request->peer_login +1));
        blen += base64_encode_final(&ctx, loginbuf+blen);
        httpHeaderPutStrf(hdr_out, header, "Basic %.*s", blen, loginbuf);
        return;
    }

    /* external_acl provided credentials */
    if (request->extacl_user.size() && request->extacl_passwd.size() &&
            (strcmp(request->peer_login, "PASS") == 0 ||
             strcmp(request->peer_login, "PROXYPASS") == 0)) {

        blen = base64_encode_update(&ctx, loginbuf, request->extacl_user.size(), reinterpret_cast<const uint8_t*>(request->extacl_user.rawBuf()));
        blen += base64_encode_update(&ctx, loginbuf+blen, 1, reinterpret_cast<const uint8_t*>(":"));
        blen += base64_encode_update(&ctx, loginbuf+blen, request->extacl_passwd.size(), reinterpret_cast<const uint8_t*>(request->extacl_passwd.rawBuf()));
        blen += base64_encode_final(&ctx, loginbuf+blen);
        httpHeaderPutStrf(hdr_out, header, "Basic %.*s", blen, loginbuf);
        return;
    }
    // if no external user credentials are available to fake authentication with PASS acts like PASSTHRU
