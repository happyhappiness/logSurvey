	return result;
}

#ifndef NO_CURL
static int curl_transport_push(struct transport *transport, int refspec_nr, const char **refspec, int flags)
{
