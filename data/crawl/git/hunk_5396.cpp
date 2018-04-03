 			    "of non-bare repository", current_branch->refname);
 }
 
+static int truncate_fetch_head(void)
+{
+	char *filename = git_path("FETCH_HEAD");
+	FILE *fp = fopen(filename, "w");
+
+	if (!fp)
+		return error("cannot open %s: %s\n", filename, strerror(errno));
+	fclose(fp);
+	return 0;
+}
+
 static int do_fetch(struct transport *transport,
 		    struct refspec *refs, int ref_count)
 {
