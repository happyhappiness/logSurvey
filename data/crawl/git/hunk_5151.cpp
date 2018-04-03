 	return ret;
 }
 
+void handle_ignore_submodules_arg(struct diff_options *diffopt,
+				  const char *arg)
+{
+	if (!strcmp(arg, "all"))
+		DIFF_OPT_SET(diffopt, IGNORE_SUBMODULES);
+	else if (!strcmp(arg, "untracked"))
+		DIFF_OPT_SET(diffopt, IGNORE_UNTRACKED_IN_SUBMODULES);
+	else if (!strcmp(arg, "dirty"))
+		DIFF_OPT_SET(diffopt, IGNORE_DIRTY_SUBMODULES);
+	else
+		die("bad --ignore-submodules argument: %s", arg);
+}
+
 void show_submodule_summary(FILE *f, const char *path,
 		unsigned char one[20], unsigned char two[20],
 		unsigned dirty_submodule,
