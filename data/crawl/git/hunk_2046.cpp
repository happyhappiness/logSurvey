 	char buf[1024];
 
 	if (gethostname(buf, sizeof(buf))) {
-		warning("cannot get host name: %s", strerror(errno));
+		warning_errno("cannot get host name");
 		strbuf_addstr(out, "(none)");
 		*is_bogus = 1;
 		return;