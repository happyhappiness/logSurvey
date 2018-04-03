
	alias = alias_lookup(cmd);
	if (alias) {
		printf_ln(_("'%s' is aliased to '%s'"), cmd, alias);
		free(alias);
		exit(0);
	}