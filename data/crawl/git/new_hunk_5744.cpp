	} else if (!prefixcmp(url, "http://")
	        || !prefixcmp(url, "https://")
	        || !prefixcmp(url, "ftp://")) {
		transport_helper_init(ret);
#ifdef NO_CURL
		error("git was compiled without libcurl support.");
#else
		ret->push = curl_transport_push;
#endif

	} else if (is_local(url) && is_file(url)) {
		struct bundle_transport_data *data = xcalloc(1, sizeof(*data));