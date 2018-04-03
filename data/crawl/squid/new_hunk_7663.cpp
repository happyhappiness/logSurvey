    return (NULL);
}

void hierarchyNote(request, code, timeout, cache_host)
     request_t *request;
     hier_code code;
     int timeout;
     char *cache_host;
{
    if (request) {
	request->hierarchy.code = code;
	request->hierarchy.timeout = timeout;
	request->hierarchy.host = xstrdup(cache_host);
    }
}

static int edgeWouldBePinged(e, request)
