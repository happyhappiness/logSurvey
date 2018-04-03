 	while ((pos = strstr(str, "%1")) != NULL) {
 		str = realloc(str, st_add(++str_len, 1));
 		if (!str) {
-			warning("realloc failed: '%s'", strerror(errno));
+			warning_errno("realloc failed");
 			return;
 		}
 		memmove(pos + 2, pos + 1, strlen(pos));