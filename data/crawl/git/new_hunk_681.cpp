			strbuf_release(&url);
		}

		if (!proxy_auth.host)
			die("Invalid proxy URL '%s'", curl_http_proxy);

		curl_easy_setopt(result, CURLOPT_PROXY, proxy_auth.host);
#if LIBCURL_VERSION_NUM >= 0x071304
		var_override(&curl_no_proxy, getenv("NO_PROXY"));