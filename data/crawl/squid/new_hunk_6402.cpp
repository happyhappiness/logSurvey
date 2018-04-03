void
httpHeaderPutAuth(HttpHeader * hdr, const char *authScheme, const char *realm)
{
    assert(hdr && authScheme && realm);
    httpHeaderPutStrf(hdr, HDR_WWW_AUTHENTICATE, "%s realm=\"%s\"", authScheme, realm);
}

void
