			aborted = 1;
		}
	} else if (request->state == RUN_FETCH_LOOSE) {
		close(request->local_fileno);
		request->local_fileno = -1;

		if (request->curl_result != CURLE_OK &&
		    request->http_code != 416) {
			if (stat(request->tmpfile, &st) == 0) {
				if (st.st_size == 0)
					unlink_or_warn(request->tmpfile);
			}
		} else {
			if (request->http_code == 416)
				warning("requested range invalid; we may already have all the data.");

			git_inflate_end(&request->stream);
			git_SHA1_Final(request->real_sha1, &request->c);
			if (request->zret != Z_STREAM_END) {
				unlink_or_warn(request->tmpfile);
			} else if (hashcmp(request->obj->sha1, request->real_sha1)) {
				unlink_or_warn(request->tmpfile);
			} else {
				request->rename =
					move_temp_to_file(
						request->tmpfile,
						request->filename);
				if (request->rename == 0)
					request->obj->flags |= (LOCAL | REMOTE);
			}
		}

		/* Try fetching packed if necessary */
		if (request->obj->flags & LOCAL)
			release_request(request);
		else
			start_fetch_packed(request);

	} else if (request->state == RUN_FETCH_PACKED) {
