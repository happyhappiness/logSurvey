 
 void add_excludes_from_file(struct dir_struct *dir, const char *fname)
 {
-	if (add_excludes_from_file_1(fname, "", 0,
+	if (add_excludes_from_file_1(fname, "", 0, NULL,
 				     &dir->exclude_list[EXC_FILE]) < 0)
 		die("cannot use %s as an exclude file", fname);
 }
 
-int push_exclude_per_directory(struct dir_struct *dir, const char *base, int baselen)
+static void prep_exclude(struct dir_struct *dir, const char *base, int baselen)
 {
-	char exclude_file[PATH_MAX];
-	struct exclude_list *el = &dir->exclude_list[EXC_DIRS];
-	int current_nr = el->nr;
-
-	if (dir->exclude_per_dir) {
-		memcpy(exclude_file, base, baselen);
-		strcpy(exclude_file + baselen, dir->exclude_per_dir);
-		add_excludes_from_file_1(exclude_file, base, baselen, el);
+	struct exclude_list *el;
+	struct exclude_stack *stk = NULL;
+	int current;
+
+	if ((!dir->exclude_per_dir) ||
+	    (baselen + strlen(dir->exclude_per_dir) >= PATH_MAX))
+		return; /* too long a path -- ignore */
+
+	/* Pop the ones that are not the prefix of the path being checked. */
+	el = &dir->exclude_list[EXC_DIRS];
+	while ((stk = dir->exclude_stack) != NULL) {
+		if (stk->baselen <= baselen &&
+		    !strncmp(dir->basebuf, base, stk->baselen))
+			break;
+		dir->exclude_stack = stk->prev;
+		while (stk->exclude_ix < el->nr)
+			free(el->excludes[--el->nr]);
+		free(stk->filebuf);
+		free(stk);
 	}
-	return current_nr;
-}
 
-void pop_exclude_per_directory(struct dir_struct *dir, int stk)
-{
-	struct exclude_list *el = &dir->exclude_list[EXC_DIRS];
+	/* Read from the parent directories and push them down. */
+	current = stk ? stk->baselen : -1;
+	while (current < baselen) {
+		struct exclude_stack *stk = xcalloc(1, sizeof(*stk));
+		const char *cp;
 
-	while (stk < el->nr)
-		free(el->excludes[--el->nr]);
+		if (current < 0) {
+			cp = base;
+			current = 0;
+		}
+		else {
+			cp = strchr(base + current + 1, '/');
+			if (!cp)
+				die("oops in prep_exclude");
+			cp++;
+		}
+		stk->prev = dir->exclude_stack;
+		stk->baselen = cp - base;
+		stk->exclude_ix = el->nr;
+		memcpy(dir->basebuf + current, base + current,
+		       stk->baselen - current);
+		strcpy(dir->basebuf + stk->baselen, dir->exclude_per_dir);
+		add_excludes_from_file_1(dir->basebuf,
+					 dir->basebuf, stk->baselen,
+					 &stk->filebuf, el);
+		dir->exclude_stack = stk;
+		current = stk->baselen;
+	}
+	dir->basebuf[baselen] = '\0';
 }
 
 /* Scan the list and let the last match determines the fate.
