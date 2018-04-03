 		fprintf(stderr, "Checking %s %s\n",
 			typename(obj->type), sha1_to_hex(obj->sha1));
 
-	if (fsck_walk(obj, mark_used, 0))
+	if (fsck_walk(obj, mark_used, NULL))
 		objerror(obj, "broken links");
 	if (fsck_object(obj, check_strict, fsck_error_func))
 		return -1;
