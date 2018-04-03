	if (start_active_slot(slot)) {
		run_active_slot(slot);
		if (results.curl_result != CURLE_OK) {
			ret = error("Unable to get pack index %s\n%s", url,
				    curl_errorstr);
			goto cleanup_index;
		}
	} else {
		ret = error("Unable to start request");
		goto cleanup_index;
	}

	ret = move_temp_to_file(tmpfile, filename);

cleanup_index:
	fclose(indexfile);
	slot->local = NULL;
cleanup_pack:
	free(url);
	free(hex);
	return ret;
}

static int setup_index(unsigned char *sha1)
