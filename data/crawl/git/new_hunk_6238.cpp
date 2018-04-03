	die("git-push is not available for http/https repository when not compiled with USE_CURL_MULTI");
#endif

	if (!repo->url)
		usage(http_push_usage);

	if (delete_branch && nr_refspec != 1)
		die("You must specify only one branch name when deleting a remote branch");

	memset(remote_dir_exists, -1, 256);

	/*
	 * Create a minimum remote by hand to give to http_init(),
	 * primarily to allow it to look at the URL.
	 */
	remote = xcalloc(sizeof(*remote), 1);
	ALLOC_GROW(remote->url, remote->url_nr + 1, remote->url_alloc);
	remote->url[remote->url_nr++] = repo->url;
	http_init(remote);

	no_pragma_header = curl_slist_append(no_pragma_header, "Pragma:");

	if (repo->url && repo->url[strlen(repo->url)-1] != '/') {
		rewritten_url = xmalloc(strlen(repo->url)+2);
		strcpy(rewritten_url, repo->url);
		strcat(rewritten_url, "/");
		repo->path = rewritten_url + (repo->path - repo->url);
		repo->path_len++;
		repo->url = rewritten_url;
	}

	/* Verify DAV compliance/lock support */
