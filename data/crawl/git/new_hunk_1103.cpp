	if (!email) {
		if (strict && ident_use_config_only
		    && !(ident_config_given & IDENT_MAIL_GIVEN)) {
			fputs(_(env_hint), stderr);
			die("no email was given and auto-detection is disabled");
		}
		email = ident_default_email();
		if (strict && default_email_is_bogus) {
			fputs(_(env_hint), stderr);
			die("unable to auto-detect email address (got '%s')", email);
		}
	}