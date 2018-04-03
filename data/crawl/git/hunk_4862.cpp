 
 	return 0;
 }
+
+int cmd_repo_config(int argc, const char **argv, const char *prefix)
+{
+	fprintf(stderr, "WARNING: git repo-config is deprecated in favor of git config.\n");
+	return cmd_config(argc, argv, prefix);
+}
