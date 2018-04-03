	} else if (!prefixcmp(url, "http://")
	        || !prefixcmp(url, "https://")
	        || !prefixcmp(url, "ftp://")) {
		ret->get_refs_list = get_refs_via_curl;
		ret->fetch = fetch_objs_via_curl;
		ret->push = curl_transport_push;
		ret->disconnect = disconnect_walker;

	} else if (is_local(url) && is_file(url)) {