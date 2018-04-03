		free(to_free);
		return 0; /* file does not exist */
	}
	die_errno(_("failed to stat '%s'"), arg);
}

static void NORETURN die_verify_filename(const char *prefix,
