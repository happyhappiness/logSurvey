			XML_ParserFree(parser);
			if (!lock_flags)
				error("Error: no DAV locking support on %s",
				      repo->url);

		} else {
			error("Cannot access URL %s, return code %d",
			      repo->url, results.curl_result);
			lock_flags = 0;
		}
	} else {
		error("Unable to start PROPFIND request on %s", repo->url);
	}

	strbuf_release(&out_buffer.buf);
