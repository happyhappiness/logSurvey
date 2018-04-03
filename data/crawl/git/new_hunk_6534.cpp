			if (request->http_code == 416)
				fprintf(stderr, "Warning: requested range invalid; we may already have all the data.\n");

			git_inflate_end(&request->stream);
			SHA1_Final(request->real_sha1, &request->c);
			if (request->zret != Z_STREAM_END) {
				unlink(request->tmpfile);
