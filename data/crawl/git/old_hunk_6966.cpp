		result = for_each_remote(get_one_remote_for_update, &list);

	for (i = 0; i < list.nr; i++)
		result |= fetch_remote(list.items[i].path);

	/* all names were strdup()ed or strndup()ed */
	list.strdup_paths = 1;
	path_list_clear(&list, 0);

	return result;
}

static int get_one_entry(struct remote *remote, void *priv)
{
	struct path_list *list = priv;

	path_list_append(remote->name, list)->util = remote->url_nr ?
		(void *)remote->url[0] : NULL;
	if (remote->url_nr > 1)
		warning("Remote %s has more than one URL", remote->name);
