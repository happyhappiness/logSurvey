NORETURN
static void die_bad_number(const char *name, const char *value)
{
	if (!value)
		value = "";

	if (!(cf && cf->name))
		die(errno == ERANGE
		    ? _("bad numeric config value '%s' for '%s': out of range")
		    : _("bad numeric config value '%s' for '%s': invalid unit"),
		    value, name);

	switch (cf->origin_type) {
	case CONFIG_ORIGIN_BLOB:
		die(errno == ERANGE
		    ? _("bad numeric config value '%s' for '%s' in blob %s: out of range")
		    : _("bad numeric config value '%s' for '%s' in blob %s: invalid unit"),
		    value, name, cf->name);
	case CONFIG_ORIGIN_FILE:
		die(errno == ERANGE
		    ? _("bad numeric config value '%s' for '%s' in file %s: out of range")
		    : _("bad numeric config value '%s' for '%s' in file %s: invalid unit"),
		    value, name, cf->name);
	case CONFIG_ORIGIN_STDIN:
		die(errno == ERANGE
		    ? _("bad numeric config value '%s' for '%s' in standard input: out of range")
		    : _("bad numeric config value '%s' for '%s' in standard input: invalid unit"),
		    value, name);
	case CONFIG_ORIGIN_SUBMODULE_BLOB:
		die(errno == ERANGE
		    ? _("bad numeric config value '%s' for '%s' in submodule-blob %s: out of range")
		    : _("bad numeric config value '%s' for '%s' in submodule-blob %s: invalid unit"),
		    value, name, cf->name);
	case CONFIG_ORIGIN_CMDLINE:
		die(errno == ERANGE
		    ? _("bad numeric config value '%s' for '%s' in command line %s: out of range")
		    : _("bad numeric config value '%s' for '%s' in command line %s: invalid unit"),
		    value, name, cf->name);
	default:
		die(errno == ERANGE
		    ? _("bad numeric config value '%s' for '%s' in %s: out of range")
		    : _("bad numeric config value '%s' for '%s' in %s: invalid unit"),
		    value, name, cf->name);
	}
}

int git_config_int(const char *name, const char *value)
