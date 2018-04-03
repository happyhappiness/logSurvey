		/* process any boundary lines */
		if (content_top->boundary && is_multipart_boundary(line)) {
			/* flush any leftover */
			if (np != newline)
				handle_filter(newline, sizeof(newline),
					      np - newline);
			if (!handle_boundary())
				return;
		}

		/* Unwrap transfer encoding */
		len = decode_transfer_encoding(line, sizeof(line), len);
		if (len < 0) {
			error("Malformed input line");
			return;
		}

		switch (transfer_encoding) {
		case TE_BASE64:
