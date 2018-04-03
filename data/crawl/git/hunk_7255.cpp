 	strbuf_init(&buf, 0);
 	strbuf_init(&buf2, 0);
 
+	strbuf_addf(&buf2, "refs/heads/test:refs/remotes/%s/test", name);
+	if (!valid_fetch_refspec(buf2.buf))
+		die("'%s' is not a valid remote name", name);
+
 	strbuf_addf(&buf, "remote.%s.url", name);
 	if (git_config_set(buf.buf, url))
 		return 1;
 
+	strbuf_reset(&buf);
+	strbuf_addf(&buf, "remote.%s.fetch", name);
+
 	if (track.nr == 0)
 		path_list_append("*", &track);
 	for (i = 0; i < track.nr; i++) {
 		struct path_list_item *item = track.items + i;
 
-		strbuf_reset(&buf);
-		strbuf_addf(&buf, "remote.%s.fetch", name);
-
 		strbuf_reset(&buf2);
 		if (mirror)
 			strbuf_addf(&buf2, "refs/%s:refs/%s",
