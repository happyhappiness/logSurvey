{
	struct string_list *list = priv;

	if (remote->url_nr > 0) {
		int i;

		for (i = 0; i < remote->url_nr; i++)
			string_list_append(remote->name, list)->util = (void *)remote->url[i];
	} else
		string_list_append(remote->name, list)->util = NULL;

	return 0;
}
