 	mailname = fopen("/etc/mailname", "r");
 	if (!mailname) {
 		if (errno != ENOENT)
-			warning("cannot open /etc/mailname: %s",
-				strerror(errno));
+			warning_errno("cannot open /etc/mailname");
 		return -1;
 	}
 	if (strbuf_getline(&mailnamebuf, mailname) == EOF) {
 		if (ferror(mailname))
-			warning("cannot read /etc/mailname: %s",
-				strerror(errno));
+			warning_errno("cannot read /etc/mailname");
 		strbuf_release(&mailnamebuf);
 		fclose(mailname);
 		return -1;
