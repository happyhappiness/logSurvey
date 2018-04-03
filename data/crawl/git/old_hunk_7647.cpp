		fprintf(stderr, "Unable to start PROPFIND request\n");
	}

	free(out_data);
	free(in_buffer.buffer);
	curl_slist_free_all(dav_headers);

	return lock_flags;
