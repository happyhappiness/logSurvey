    r->handler(r->data);
    delete r;
}

void
Auth::Negotiate::UserRequest::addAuthenticationInfoHeader(HttpReply * rep, int accel)
{
    http_hdr_type type;

    if (!server_blob)
        return;

    /* don't add to authentication error pages */
    if ((!accel && rep->sline.status() == Http::scProxyAuthenticationRequired)
            || (accel && rep->sline.status() == Http::scUnauthorized))
        return;

    type = accel ? HDR_AUTHENTICATION_INFO : HDR_PROXY_AUTHENTICATION_INFO;
    httpHeaderPutStrf(&rep->header, type, "Negotiate %s", server_blob);

    safe_free(server_blob);
}

