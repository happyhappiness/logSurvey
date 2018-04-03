 
 static int rename_tmp_log(const char *newrefname)
 {
-	char *path = git_pathdup("logs/%s", newrefname);
-	int ret, true_errno;
+	struct strbuf path = STRBUF_INIT;
+	struct strbuf tmp = STRBUF_INIT;
+	struct rename_cb cb;
+	int ret;
 
-	ret = raceproof_create_file(path, rename_tmp_log_callback, &true_errno);
+	strbuf_git_path(&path, "logs/%s", newrefname);
+	strbuf_git_path(&tmp, TMP_RENAMED_LOG);
+	cb.tmp_renamed_log = tmp.buf;
+	ret = raceproof_create_file(path.buf, rename_tmp_log_callback, &cb);
 	if (ret) {
 		if (errno == EISDIR)
-			error("directory not empty: %s", path);
+			error("directory not empty: %s", path.buf);
 		else
 			error("unable to move logfile %s to %s: %s",
-			      git_path(TMP_RENAMED_LOG), path,
-			      strerror(true_errno));
+			      tmp.buf, path.buf,
+			      strerror(cb.true_errno));
 	}
 
-	free(path);
+	strbuf_release(&path);
+	strbuf_release(&tmp);
 	return ret;
 }
 
