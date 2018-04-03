			return -1;
		return 0;
	} else if (!strcmp(name, "push-option")) {
		string_list_append(&options.push_options, value);
		return 0;

#if LIBCURL_VERSION_NUM >= 0x070a08
