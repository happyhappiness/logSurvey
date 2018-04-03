 		else if (S_ISDIR(st.st_mode))
 			src = git_link;
 		else
-			die("unable to handle file type %d", st.st_mode);
+			die(_("unable to handle file type %d"), st.st_mode);
 
 		if (rename(src, git_dir))
-			die_errno("unable to move %s to %s", src, git_dir);
+			die_errno(_("unable to move %s to %s"), src, git_dir);
 	}
 
 	fp = fopen(git_link, "w");
 	if (!fp)
-		die("Could not create git link %s", git_link);
+		die(_("Could not create git link %s"), git_link);
 	fprintf(fp, "gitdir: %s\n", git_dir);
 	fclose(fp);
 }
