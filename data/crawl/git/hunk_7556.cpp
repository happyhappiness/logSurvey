 	if (!path || !strcmp(path, "/dev/null"))
 		*mode = 0;
 	else if (!strcmp(path, "-"))
-		*mode = ntohl(create_ce_mode(0666));
+		*mode = create_ce_mode(0666);
 	else if (stat(path, &st))
 		return error("Could not access '%s'", path);
 	else
