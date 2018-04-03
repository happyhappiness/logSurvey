 		const char *bad = NULL;
 
 		if (show_only)
-			printf("Checking rename of '%s' to '%s'\n", src, dst);
+			printf(_("Checking rename of '%s' to '%s'\n"), src, dst);
 
 		length = strlen(src);
 		if (lstat(src, &st) < 0)
