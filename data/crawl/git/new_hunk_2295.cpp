			fputs(env_hint, stderr);
			die("unable to auto-detect email address (got '%s')", email);
		}
		if (strict && ident_use_config_only
		    && !(ident_config_given & IDENT_MAIL_GIVEN))
			die("user.useConfigOnly set but no mail given");
	}

	strbuf_reset(&ident);
