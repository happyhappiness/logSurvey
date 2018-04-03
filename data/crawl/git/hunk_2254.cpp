 
 	strbuf_reset(&buf);
 	strbuf_addf(&buf, "remote.%s.fetch", rename.new);
-	if (git_config_set_multivar(buf.buf, NULL, NULL, 1))
-		return error(_("Could not remove config section '%s'"), buf.buf);
+	git_config_set_multivar_or_die(buf.buf, NULL, NULL, 1);
 	strbuf_addf(&old_remote_context, ":refs/remotes/%s/", rename.old);
 	for (i = 0; i < oldremote->fetch_refspec_nr; i++) {
 		char *ptr;
