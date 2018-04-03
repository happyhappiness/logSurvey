 	int fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600);
 
 	if (fd < 0)
-		die("could not create file '%s': %s",
-		    filename, strerror(errno));
+		die_errno("could not create file '%s'", filename);
 
 	bisect_rev_hex[len] = '\n';
 	write_or_die(fd, bisect_rev_hex, len + 1);
