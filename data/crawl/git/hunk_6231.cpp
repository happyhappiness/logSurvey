 	if (push_verbosely)
 		fprintf(stderr, "Getting pack list\n");
 
-	url = xmalloc(strlen(remote->url) + 20);
-	sprintf(url, "%sobjects/info/packs", remote->url);
+	url = xmalloc(strlen(repo->url) + 20);
+	sprintf(url, "%sobjects/info/packs", repo->url);
 
 	slot = get_active_slot();
 	slot->results = &results;
