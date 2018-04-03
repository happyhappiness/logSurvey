	curl_easy_setopt(result, CURLOPT_REDIR_PROTOCOLS, allowed_protocols);
	curl_easy_setopt(result, CURLOPT_PROTOCOLS, allowed_protocols);
#else
	if (transport_restrict_protocols())
		warning("protocol restrictions not applied to curl redirects because\n"
			"your curl version is too old (>= 7.19.4)");
#endif

	if (getenv("GIT_CURL_VERBOSE"))
