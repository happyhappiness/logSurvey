	return retcode;
}

static void set_option(const char *name, const char *value)
{
	int r = transport_set_option(gtransport, name, value);
	if (r < 0)
		die(_("Option \"%s\" value \"%s\" is not valid for %s"),
		    name, value, gtransport->url);
	if (r > 0)
		warning(_("Option \"%s\" is ignored for %s\n"),
			name, gtransport->url);
}

static int get_one_remote_for_fetch(struct remote *remote, void *priv)
{
	struct string_list *list = priv;
