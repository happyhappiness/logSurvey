	if (!oldremote)
		die("No such remote: %s", rename.old);

	newremote = remote_get(rename.new);
	if (newremote && (newremote->url_nr > 1 || newremote->fetch_refspec_nr))
		die("remote %s already exists.", rename.new);
