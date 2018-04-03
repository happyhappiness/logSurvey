 	curl_easy_setopt(curl, CURLOPT_PORT, server.port);
 
 	if (server.auth_method) {
+#if LIBCURL_VERSION_NUM < 0x072200
+		warning("No LOGIN_OPTIONS support in this cURL version");
+#else
 		struct strbuf auth = STRBUF_INIT;
 		strbuf_addstr(&auth, "AUTH=");
 		strbuf_addstr(&auth, server.auth_method);
 		curl_easy_setopt(curl, CURLOPT_LOGIN_OPTIONS, auth.buf);
 		strbuf_release(&auth);
+#endif
 	}
 
 	if (!server.use_ssl)