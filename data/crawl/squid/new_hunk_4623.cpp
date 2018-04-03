    return NULL;
}

extern string httpHeaderGetList(const HttpHeader * hdr, http_hdr_type id)
{
    fatal ("dummy function\n");
    return "";
}

SQUIDCEXTERN int httpHeaderHas(const HttpHeader * hdr, http_hdr_type type)
