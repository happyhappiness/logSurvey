 	char *name;
 
 	if (!dir)
-		die("cannot opendir %s (%s)", path, strerror(errno));
+		die_errno("cannot opendir '%s'", path);
 	strcpy(pathbuf, path);
 	name = pathbuf + strlen(path);
 	*name++ = '/';
