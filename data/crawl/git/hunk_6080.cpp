 		path = git_path("remotes/%s", remote->name);
 	else if (remote->origin == REMOTE_BRANCHES)
 		path = git_path("branches/%s", remote->name);
-	if (path && unlink(path))
-		warning("failed to remove '%s'", path);
+	if (path)
+		unlink_or_warn(path);
 	return 0;
 }
 
