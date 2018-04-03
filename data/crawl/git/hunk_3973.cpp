 	}
 	return path;
 }
+
+/*
+ * Dies if the given path refers to a file inside a symlinked
+ * directory in the index.
+ */
+void die_if_path_beyond_symlink(const char *path, const char *prefix)
+{
+	if (has_symlink_leading_path(path, strlen(path))) {
+		int len = prefix ? strlen(prefix) : 0;
+		die(_("'%s' is beyond a symbolic link"), path + len);
+	}
+}
