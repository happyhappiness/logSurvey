		transport_helper_init(ret, "curl");
#ifdef NO_CURL
		error("git was compiled without libcurl support.");
#else
		ret->push = curl_transport_push;
#endif

	} else if (is_local(url) && is_file(url)) {