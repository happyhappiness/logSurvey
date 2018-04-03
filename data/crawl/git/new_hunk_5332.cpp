			fprintf(stderr, "Skipping account %s@%s, server forbids LOGIN\n", srvc->user, srvc->host);
			goto bail;
		}

		if (srvc->auth_method) {
			struct imap_cmd_cb cb;
