		if (!name) {
			if (strict && ident_use_config_only
			    && !(ident_config_given & IDENT_NAME_GIVEN)) {
				fputs(_(env_hint), stderr);
				die("no name was given and auto-detection is disabled");
			}
			name = ident_default_name();
			using_default = 1;
			if (strict && default_name_is_bogus) {
				fputs(_(env_hint), stderr);
				die("unable to auto-detect name (got '%s')", name);
			}
		}
		if (!*name) {
			struct passwd *pw;
			if (strict) {
				if (using_default)
					fputs(_(env_hint), stderr);
				die("empty ident name (for <%s>) not allowed", email);
			}
			pw = xgetpwuid_self(NULL);
