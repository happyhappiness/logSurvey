	curl_easy_setopt(curl, CURLOPT_PORT, server.port);

	if (server.auth_method) {
		struct strbuf auth = STRBUF_INIT;
		strbuf_addstr(&auth, "AUTH=");
		strbuf_addstr(&auth, server.auth_method);
		curl_easy_setopt(curl, CURLOPT_LOGIN_OPTIONS, auth.buf);
		strbuf_release(&auth);
	}

	if (!server.use_ssl)