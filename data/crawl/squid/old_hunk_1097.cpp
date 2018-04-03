    }
#endif /* HAVE_KRB5 && HAVE_GSSAPI */

    httpHeaderPutStrf(hdr_out, header, "Basic %s",
                      old_base64_encode(request->peer_login));
    return;
}

