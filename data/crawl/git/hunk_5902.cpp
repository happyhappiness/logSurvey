 			continue;
 		strcpy(name, de->d_name);
 		if (lstat(pathbuf, &st))
-			die("cannot lstat %s (%s)", pathbuf, strerror(errno));
+			die_errno("cannot lstat '%s'", pathbuf);
 		if (S_ISDIR(st.st_mode))
 			remove_subtree(pathbuf);
 		else if (unlink(pathbuf))
-			die("cannot unlink %s (%s)", pathbuf, strerror(errno));
+			die_errno("cannot unlink '%s'", pathbuf);
 	}
 	closedir(dir);
 	if (rmdir(path))
-		die("cannot rmdir %s (%s)", path, strerror(errno));
+		die_errno("cannot rmdir '%s'", path);
 }
 
 static int create_file(const char *path, unsigned int mode)
