{
	struct string_list *list = priv;

	string_list_append(remote->name, list)->util = remote->url_nr ?
		(void *)remote->url[0] : NULL;
	if (remote->url_nr > 1)
		warning("Remote %s has more than one URL", remote->name);

	return 0;
}
