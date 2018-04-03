	}

	if (http_is_verbose)
		fprintf(stderr, "Getting index for pack %s\n", sha1_to_hex(sha1));

	end_url_with_slash(&buf, base_url);
	strbuf_addf(&buf, "objects/pack/pack-%s.idx", sha1_to_hex(sha1));
	url = strbuf_detach(&buf, NULL);

	filename = sha1_pack_index_name(sha1);
	if (http_get_file(url, filename, 0) != HTTP_OK)
		ret = error("Unable to get pack index %s\n", url);

cleanup:
	free(url);
	return ret;
}