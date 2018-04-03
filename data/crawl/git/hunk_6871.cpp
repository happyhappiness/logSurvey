 				const char *branch1)
 {
 	char *new_path = unique_path(ren1->pair->two->path, branch1);
-	output(1, "Renamed %s to %s instead", ren1->pair->one->path, new_path);
+	output(1, "Renaming %s to %s instead", ren1->pair->one->path, new_path);
 	remove_file(0, ren1->pair->two->path, 0);
 	update_file(0, ren1->pair->two->sha1, ren1->pair->two->mode, new_path);
 	free(new_path);
