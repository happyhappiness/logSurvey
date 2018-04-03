	int ret = http_request(url, type, result, target, options);
	if (ret != HTTP_REAUTH)
		return ret;
	return http_request(url, type, result, target, options);
}

