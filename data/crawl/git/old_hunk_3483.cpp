	return ret;
}

static int http_request_reauth(const char *url,
			       void *result, int target,
			       struct http_get_options *options)
{
	int ret = http_request(url, result, target, options);
	if (ret != HTTP_REAUTH)
		return ret;

