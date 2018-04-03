 		path = git_pathdup("TAG_EDITMSG");
 		fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0600);
 		if (fd < 0)
-			die_errno("could not create file '%s'", path);
+			die_errno(_("could not create file '%s'"), path);
 
 		if (!is_null_sha1(prev))
 			write_tag_body(fd, prev);
