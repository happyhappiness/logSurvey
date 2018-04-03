		fprintf(stderr, "Unable to start PROPFIND request\n");
	}

	strbuf_release(&out_buffer.buf);
	strbuf_release(&in_buffer);
	curl_slist_free_all(dav_headers);

	return lock_flags;
