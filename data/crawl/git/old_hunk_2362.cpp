				fputs(env_hint, stderr);
			die("empty ident name (for <%s>) not allowed", email);
		}
		pw = xgetpwuid_self();
		name = pw->pw_name;
	}

	if (strict && email == git_default_email.buf && default_email_is_bogus) {
		fputs(env_hint, stderr);
		die("unable to auto-detect email address (got '%s')", email);