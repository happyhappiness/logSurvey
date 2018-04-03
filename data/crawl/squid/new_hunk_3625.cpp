	snprintf(loginbuf, sizeof(loginbuf), SQUIDSTRINGPH ":" SQUIDSTRINGPH,
		 SQUIDSTRINGPRINT(orig_request->extacl_user),
		 SQUIDSTRINGPRINT(orig_request->extacl_passwd));
	httpHeaderPutStrf(hdr_out, header, "Basic %s",
			  base64_encode(loginbuf));
	return;
    }

    httpHeaderPutStrf(hdr_out, header, "Basic %s",
		      base64_encode(orig_request->peer_login));
    return;
}