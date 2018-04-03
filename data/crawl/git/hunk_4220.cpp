 		else if (S_ISDIR(st.st_mode))
 			src = git_link;
 		else
-			die(_("unable to handle file type %d"), st.st_mode);
+			die(_("unable to handle file type %d"), (int)st.st_mode);
 
 		if (rename(src, git_dir))
 			die_errno(_("unable to move %s to %s"), src, git_dir);