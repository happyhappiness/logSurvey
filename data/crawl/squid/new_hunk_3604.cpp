	return;
    }

    /* Kerberos login to peer */
#if HAVE_KRB5 && HAVE_GSSAPI
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
        return;
    }
#endif /* HAVE_KRB5 && HAVE_GSSAPI */

    httpHeaderPutStrf(hdr_out, header, "Basic %s",
		      base64_encode(orig_request->peer_login));
    return;
