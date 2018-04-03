{
    fatal ("Not implemented");
}

bool
HttpReply::sanityCheckStartLine(MemBuf *buf, http_status *error)
{
    fatal ("Not implemented");
    return false;
}

int
HttpReply::httpMsgParseError()
{
    fatal ("Not implemented");
    return 0;
}

bool
HttpReply::expectingBody(method_t, ssize_t&) const
{
    fatal ("Not implemented");
    return false;
}

void
HttpReply::packFirstLineInto(Packer * p, bool) const
{
    fatal ("Not implemented");
}

bool
HttpReply::parseFirstLine(const char *start, const char *end)
{
    fatal ("Not implemented");
    return false;
}

void
HttpReply::hdrCacheInit()
{
    fatal ("Not implemented");
}