 	strbuf_release(&nbuf);
 
 	if (close(fd) < 0)
-		die("closing file %s: %s", path, strerror(errno));
+		die_errno("closing file '%s'", path);
 	return 0;
 }
 
