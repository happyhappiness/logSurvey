	if (is_transport_allowed("ftps"))
		allowed_protocols |= CURLPROTO_FTPS;
	curl_easy_setopt(result, CURLOPT_REDIR_PROTOCOLS, allowed_protocols);
	curl_easy_setopt(result, CURLOPT_PROTOCOLS, allowed_protocols);
#else
	if (transport_restrict_protocols())
		warning("protocol restrictions not applied to curl redirects because\n"
