}

bool
HttpRequest::expectingBody(method_t unused, ssize_t&) const
{
    fatal("Not implemented");
    return false;
