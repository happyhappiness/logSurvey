 	exit(1);
 }
 
-int split_mbox(const char **mbox, const char *dir, int allow_bare, int nr_prec, int skip)
+static int populate_maildir_list(struct path_list *list, const char *path)
 {
-	char *name = xmalloc(strlen(dir) + 2 + 3 * sizeof(skip));
+	DIR *dir;
+	struct dirent *dent;
+
+	if ((dir = opendir(path)) == NULL) {
+		error("cannot opendir %s (%s)", path, strerror(errno));
+		return -1;
+	}
+
+	while ((dent = readdir(dir)) != NULL) {
+		if (dent->d_name[0] == '.')
+			continue;
+		path_list_insert(dent->d_name, list);
+	}
+
+	closedir(dir);
+
+	return 0;
+}
+
+static int split_maildir(const char *maildir, const char *dir,
+	int nr_prec, int skip)
+{
+	char file[PATH_MAX];
+	char curdir[PATH_MAX];
+	char name[PATH_MAX];
 	int ret = -1;
+	int i;
+	struct path_list list = {NULL, 0, 0, 1};
 
-	while (*mbox) {
-		const char *file = *mbox++;
-		FILE *f = !strcmp(file, "-") ? stdin : fopen(file, "r");
-		int file_done = 0;
+	snprintf(curdir, sizeof(curdir), "%s/cur", maildir);
+	if (populate_maildir_list(&list, curdir) < 0)
+		goto out;
 
-		if ( !f ) {
-			error("cannot open mbox %s", file);
+	for (i = 0; i < list.nr; i++) {
+		FILE *f;
+		snprintf(file, sizeof(file), "%s/%s", curdir, list.items[i].path);
+		f = fopen(file, "r");
+		if (!f) {
+			error("cannot open mail %s (%s)", file, strerror(errno));
 			goto out;
 		}
 
 		if (fgets(buf, sizeof(buf), f) == NULL) {
-			if (f == stdin)
-				break; /* empty stdin is OK */
-			error("cannot read mbox %s", file);
+			error("cannot read mail %s (%s)", file, strerror(errno));
 			goto out;
 		}
 
-		while (!file_done) {
-			sprintf(name, "%s/%0*d", dir, nr_prec, ++skip);
-			file_done = split_one(f, name, allow_bare);
+		sprintf(name, "%s/%0*d", dir, nr_prec, ++skip);
+		split_one(f, name, 1);
+
+		fclose(f);
+	}
+
+	path_list_clear(&list, 1);
+
+	ret = skip;
+out:
+	return ret;
+}
+
+int split_mbox(const char *file, const char *dir, int allow_bare,
+		int nr_prec, int skip)
+{
+	char name[PATH_MAX];
+	int ret = -1;
+
+	FILE *f = !strcmp(file, "-") ? stdin : fopen(file, "r");
+	int file_done = 0;
+
+	if (!f) {
+		error("cannot open mbox %s", file);
+		goto out;
+	}
+
+	if (fgets(buf, sizeof(buf), f) == NULL) {
+		/* empty stdin is OK */
+		if (f != stdin) {
+			error("cannot read mbox %s", file);
+			goto out;
 		}
+		file_done = 1;
+	}
 
-		if (f != stdin)
-			fclose(f);
+	while (!file_done) {
+		sprintf(name, "%s/%0*d", dir, nr_prec, ++skip);
+		file_done = split_one(f, name, allow_bare);
 	}
+
+	if (f != stdin)
+		fclose(f);
+
 	ret = skip;
 out:
-	free(name);
 	return ret;
 }
+
 int cmd_mailsplit(int argc, const char **argv, const char *prefix)
 {
-	int nr = 0, nr_prec = 4, ret;
+	int nr = 0, nr_prec = 4, num = 0;
 	int allow_bare = 0;
 	const char *dir = NULL;
 	const char **argp;
