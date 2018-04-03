static void set_signingkey(const char *value)
{
	if (strlcpy(signingkey, value, sizeof(signingkey)) >= sizeof(signingkey))
		die(_("signing key value too long (%.10s...)"), value);
}

static int git_tag_config(const char *var, const char *value, void *cb)
