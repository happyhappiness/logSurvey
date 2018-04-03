 		else if (!strcmp(v, "all"))
 			s->show_untracked_files = SHOW_ALL_UNTRACKED_FILES;
 		else
-			return error("Invalid untracked files mode '%s'", v);
+			return error(_("Invalid untracked files mode '%s'"), v);
 		return 0;
 	}
 	return git_diff_ui_config(k, v, NULL);
