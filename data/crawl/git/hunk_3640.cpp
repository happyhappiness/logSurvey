 
 	return result;
 }
+
+void check_shallow_file_for_update(void)
+{
+	struct stat st;
+
+	if (!is_shallow)
+		return;
+	else if (is_shallow == -1)
+		die("BUG: shallow must be initialized by now");
+
+	if (stat(git_path("shallow"), &st))
+		die("shallow file was removed during fetch");
+	else if (st.st_mtime != shallow_stat.st_mtime
+#ifdef USE_NSEC
+		 || ST_MTIME_NSEC(st) != ST_MTIME_NSEC(shallow_stat)
+#endif
+		   )
+		die("shallow file was changed during fetch");
+}
