 	}
 }
 
+/*
+ * Write errors (particularly out of space) can result in
+ * failed temporary packs (and more rarely indexes and other
+ * files begining with "tmp_") accumulating in the
+ * object directory.
+ */
+static void remove_temporary_files(void)
+{
+	DIR *dir;
+	struct dirent *de;
+	char* dirname=get_object_directory();
+
+	dir = opendir(dirname);
+	if (!dir) {
+		fprintf(stderr, "Unable to open object directory %s\n",
+			dirname);
+		return;
+	}
+	while ((de = readdir(dir)) != NULL) {
+		if (!prefixcmp(de->d_name, "tmp_")) {
+			char name[PATH_MAX];
+			int c = snprintf(name, PATH_MAX, "%s/%s",
+					 dirname, de->d_name);
+			if (c < 0 || c >= PATH_MAX)
+				continue;
+			if (expire) {
+				struct stat st;
+				if (stat(name, &st) != 0 || st.st_mtime >= expire)
+					continue;
+			}
+			printf("Removing stale temporary file %s\n", name);
+			if (!show_only)
+				unlink(name);
+		}
+	}
+	closedir(dir);
+}
+
 int cmd_prune(int argc, const char **argv, const char *prefix)
 {
 	int i;
