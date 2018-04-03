		transport_helper_init(ret, "curl");
#ifdef NO_CURL
		error("git was compiled without libcurl support.");
#endif

	} else if (is_local(url) && is_file(url)) {