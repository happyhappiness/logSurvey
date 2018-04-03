				srvc->pass = xstrdup(cred.password);
		}

		if (srvc->auth_method) {
			struct imap_cmd_cb cb;

