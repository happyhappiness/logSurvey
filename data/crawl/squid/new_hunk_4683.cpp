    httpBuf.clean();
}

void ICAPModXact::makeUsernameHeader(const HttpRequest *request, MemBuf &buf) {
    if (const auth_user_request_t *auth = request->auth_user_request) {
        if (char const *name = auth->username()) {
            const char *value = TheICAPConfig.client_username_encode ?
                base64_encode(name) : name;
            buf.Printf("%s: %s\r\n", TheICAPConfig.client_username_header,
                value);
        }
    }
}

void ICAPModXact::encapsulateHead(MemBuf &icapBuf, const char *section, MemBuf &httpBuf, const HttpMsg *head)
{
    // update ICAP header
