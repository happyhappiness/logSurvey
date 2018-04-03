				fputs(env_hint, stderr);
				die("unable to auto-detect name (got '%s')", name);
			}
		}
		if (!*name) {
			struct passwd *pw;
