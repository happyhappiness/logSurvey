	return ret;
}

int http_error(const char *url, int ret)
{
	/* http_request has already handled HTTP_START_FAILED. */
	if (ret != HTTP_START_FAILED)
		error("%s while accessing %s", curl_errorstr, url);

	return ret;
}

int http_fetch_ref(const char *base, struct ref *ref)
