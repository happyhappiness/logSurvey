 	int filemode;
 
 	if (len > sizeof(path)-50)
-		die("insane git directory %s", git_dir);
+		die(_("insane git directory %s"), git_dir);
 	memcpy(path, git_dir, len);
 
 	if (len && path[len-1] != '/')
