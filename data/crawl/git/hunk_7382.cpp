 
 	/* Send delete request */
 	fprintf(stderr, "Removing remote branch '%s'\n", remote_ref->name);
+	if (dry_run)
+		return 0;
 	url = xmalloc(strlen(remote->url) + strlen(remote_ref->name) + 1);
 	sprintf(url, "%s%s", remote->url, remote_ref->name);
 	slot = get_active_slot();
