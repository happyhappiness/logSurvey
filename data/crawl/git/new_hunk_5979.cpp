	url = strbuf_detach(&buf, NULL);

	filename = sha1_pack_index_name(sha1);
	if (http_get_file(url, filename, 0) != HTTP_OK)
		ret = error("Unable to get pack index %s\n", url);

cleanup:
	free(hex);
	free(url);
	return ret;