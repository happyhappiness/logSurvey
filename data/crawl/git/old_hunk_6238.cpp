	die("git-push is not available for http/https repository when not compiled with USE_CURL_MULTI");
#endif

	if (!remote->url)
		usage(http_push_usage);

	if (delete_branch && nr_refspec != 1)
		die("You must specify only one branch name when deleting a remote branch");

	memset(remote_dir_exists, -1, 256);

	http_init(NULL);

	no_pragma_header = curl_slist_append(no_pragma_header, "Pragma:");

	if (remote->url && remote->url[strlen(remote->url)-1] != '/') {
		rewritten_url = xmalloc(strlen(remote->url)+2);
		strcpy(rewritten_url, remote->url);
		strcat(rewritten_url, "/");
		remote->path = rewritten_url + (remote->path - remote->url);
		remote->path_len++;
		remote->url = rewritten_url;
	}

	/* Verify DAV compliance/lock support */
