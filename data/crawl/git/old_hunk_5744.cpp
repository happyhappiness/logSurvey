	} else if (!prefixcmp(url, "http://")
	        || !prefixcmp(url, "https://")
	        || !prefixcmp(url, "ftp://")) {
#ifdef NO_CURL
		error("git was compiled without libcurl support.");
#else
		ret->get_refs_list = get_refs_via_curl;
		ret->fetch = fetch_objs_via_curl;
		ret->push = curl_transport_push;
#endif
		ret->disconnect = disconnect_walker;

	} else if (is_local(url) && is_file(url)) {
		struct bundle_transport_data *data = xcalloc(1, sizeof(*data));