			fputs(env_hint, stderr);
			die("unable to auto-detect email address (got '%s')", email);
		}
	}

	strbuf_reset(&ident);
