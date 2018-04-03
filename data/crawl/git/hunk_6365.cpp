 				     "of your current HEAD.\n"
 				     "If you are sure you want to delete it,"
 				     " run:\n\t'git http-push -D %s %s'",
-				     remote_ref->name, remote->url, pattern);
+				     remote_ref->name, repo->url, pattern);
 		}
 	}
 
 	/* Send delete request */
 	fprintf(stderr, "Removing remote branch '%s'\n", remote_ref->name);
 	if (dry_run)
 		return 0;
-	url = xmalloc(strlen(remote->url) + strlen(remote_ref->name) + 1);
-	sprintf(url, "%s%s", remote->url, remote_ref->name);
+	url = xmalloc(strlen(repo->url) + strlen(remote_ref->name) + 1);
+	sprintf(url, "%s%s", repo->url, remote_ref->name);
 	slot = get_active_slot();
 	slot->results = &results;
 	curl_easy_setopt(slot->curl, CURLOPT_HTTPGET, 1);
