 	cp.git_cmd = 1;
 
 	if (start_command(&cp))
-		die("could not run stash.");
+		die(_("could not run stash."));
 	len = strbuf_read(&buffer, cp.out, 1024);
 	close(cp.out);
 
 	if (finish_command(&cp) || len < 0)
-		die("stash failed");
+		die(_("stash failed"));
 	else if (!len)
 		return;
 	strbuf_setlen(&buffer, buffer.len-1);
 	if (get_sha1(buffer.buf, stash))
-		die("not a valid object: %s", buffer.buf);
+		die(_("not a valid object: %s"), buffer.buf);
 }
 
 static void read_empty(unsigned const char *sha1, int verbose)
