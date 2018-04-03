	die("git-push is not available for http/https repository when not compiled with USE_CURL_MULTI");
#endif

	if (!repo->url)
		usage(http_push_usage);

	if (delete_branch && nr_refspec != 1)
