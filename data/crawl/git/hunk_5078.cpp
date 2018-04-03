 	i = read_directory(&d, pathbuf, namelen+1, NULL);
 	if (i)
 		return o->gently ? -1 :
-			error(ERRORMSG(o, not_uptodate_dir), ce->name);
+			error(ERRORMSG(o, ERROR_NOT_UPTODATE_DIR), ce->name);
 	free(pathbuf);
 	return cnt;
 }
