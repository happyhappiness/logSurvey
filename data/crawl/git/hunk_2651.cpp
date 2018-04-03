 	if (normalize_path_copy(buf, ceil) < 0)
 		die("Path \"%s\" could not be normalized", ceil);
 	len = strlen(buf);
-	if (len > 1 && buf[len-1] == '/')
-		die("Normalized path \"%s\" ended with slash", buf);
 	free(item->string);
 	item->string = xstrdup(buf);
 	return 1;