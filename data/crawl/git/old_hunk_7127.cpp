		/* process any boundary lines */
		if (content_top->boundary && is_multipart_boundary(line)) {
			/* flush any leftover */
			if ((transfer_encoding == TE_BASE64)  &&
			    (np != newline)) {
				handle_filter(newline, sizeof(newline),
						strlen(newline));
			}
			if (!handle_boundary())
				return;
		}

		/* Unwrap transfer encoding */
		decode_transfer_encoding(line, sizeof(line));

		switch (transfer_encoding) {
		case TE_BASE64:
