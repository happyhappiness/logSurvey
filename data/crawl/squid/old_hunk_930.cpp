void HttpRequest::packFirstLineInto(Packable * p, bool full_uri) const
{
    // form HTTP request-line
    p->Printf(SQUIDSBUFPH " %s HTTP/%d.%d\r\n",
              SQUIDSBUFPRINT(method.image()),
              packableURI(full_uri),
              http_ver.major, http_ver.minor);
}

/*
