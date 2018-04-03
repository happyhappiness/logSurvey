	}

	if (!strcmp("http.postbuffer", var)) {
		http_post_buffer = git_config_int(var, value);
		if (http_post_buffer < LARGE_PACKET_MAX)
			http_post_buffer = LARGE_PACKET_MAX;
		return 0;
