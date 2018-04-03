bool
ConnStateData::proxyProtocolError(const char *msg)
{
    if (msg)
        mustStop(msg);
    return false;
}

