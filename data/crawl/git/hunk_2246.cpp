  */
 static int normalize_ceiling_entry(struct string_list_item *item, void *unused)
 {
-	const char *ceil = item->string;
-	int len = strlen(ceil);
-	char buf[PATH_MAX+1];
+	char *ceil = item->string;
 
-	if (len == 0)
+	if (!*ceil)
 		die("Empty path is not supported");
-	if (len > PATH_MAX)
-		die("Path \"%s\" is too long", ceil);
 	if (!is_absolute_path(ceil))
 		die("Path \"%s\" is not absolute", ceil);
-	if (normalize_path_copy(buf, ceil) < 0)
+	if (normalize_path_copy(ceil, ceil) < 0)
 		die("Path \"%s\" could not be normalized", ceil);
-	len = strlen(buf);
-	free(item->string);
-	item->string = xstrdup(buf);
 	return 1;
 }
 
