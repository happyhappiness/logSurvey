 		wt_status_relative_paths = git_config_bool(k, v);
 		return 0;
 	}
+	if (!strcmp(k, "status.showuntrackedfiles")) {
+		if (!v)
+			return config_error_nonbool(v);
+		else if (!strcmp(v, "no"))
+			show_untracked_files = SHOW_NO_UNTRACKED_FILES;
+		else if (!strcmp(v, "normal"))
+			show_untracked_files = SHOW_NORMAL_UNTRACKED_FILES;
+		else if (!strcmp(v, "all"))
+			show_untracked_files = SHOW_ALL_UNTRACKED_FILES;
+		else
+			return error("Invalid untracked files mode '%s'", v);
+		return 0;
+	}
 	return git_color_default_config(k, v, cb);
 }