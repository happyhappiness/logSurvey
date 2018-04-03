 
 static struct lock_file packed;
 
-int cmd_pack_refs(int argc, const char **argv, const char *prefix)
+static int pack_refs(unsigned int flags)
 {
-	int fd, i;
+	int fd;
 	struct pack_refs_cb_data cbdata;
 
 	memset(&cbdata, 0, sizeof(cbdata));
+	cbdata.flags = flags;
+
+	fd = hold_lock_file_for_update(&packed, git_path("packed-refs"), 1);
+	cbdata.refs_file = fdopen(fd, "w");
+	if (!cbdata.refs_file)
+		die("unable to create ref-pack file structure (%s)",
+		    strerror(errno));
+
+	/* perhaps other traits later as well */
+	fprintf(cbdata.refs_file, "# pack-refs with: peeled \n");
+
+	for_each_ref(handle_one_ref, &cbdata);
+	if (fflush(cbdata.refs_file) || fsync(fd) || fclose(cbdata.refs_file))
+		die("failed to write ref-pack file (%s)", strerror(errno));
+	if (commit_lock_file(&packed) < 0)
+		die("unable to overwrite old ref-pack file (%s)", strerror(errno));
+	if (cbdata.flags & PACK_REFS_PRUNE)
+		prune_refs(cbdata.ref_to_prune);
+	return 0;
+}
 
-	cbdata.prune = 1;
+int cmd_pack_refs(int argc, const char **argv, const char *prefix)
+{
+	int i;
+	unsigned int flags;
+
+	flags = PACK_REFS_PRUNE;
 	for (i = 1; i < argc; i++) {
 		const char *arg = argv[i];
 		if (!strcmp(arg, "--prune")) {
-			cbdata.prune = 1; /* now the default */
+			flags |= PACK_REFS_PRUNE; /* now the default */
 			continue;
 		}
 		if (!strcmp(arg, "--no-prune")) {
-			cbdata.prune = 0;
+			flags &= ~PACK_REFS_PRUNE;
 			continue;
 		}
 		if (!strcmp(arg, "--all")) {
-			cbdata.all = 1;
+			flags |= PACK_REFS_ALL;
 			continue;
 		}
 		/* perhaps other parameters later... */
