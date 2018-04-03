 
 static struct {
 	int nr, alloc;
-	const char **name;
+	struct {
+		const char *name;
+		char is_submodule;
+	} *entry;
 } list;
 
+static int get_ours_cache_pos(const char *path, int pos)
+{
+	int i = -pos - 1;
+
+	while ((i < active_nr) && !strcmp(active_cache[i]->name, path)) {
+		if (ce_stage(active_cache[i]) == 2)
+			return i;
+		i++;
+	}
+	return -1;
+}
+
+static int check_submodules_use_gitfiles(void)
+{
+	int i;
+	int errs = 0;
+
+	for (i = 0; i < list.nr; i++) {
+		const char *name = list.entry[i].name;
+		int pos;
+		struct cache_entry *ce;
+		struct stat st;
+
+		pos = cache_name_pos(name, strlen(name));
+		if (pos < 0) {
+			pos = get_ours_cache_pos(name, pos);
+			if (pos < 0)
+				continue;
+		}
+		ce = active_cache[pos];
+
+		if (!S_ISGITLINK(ce->ce_mode) ||
+		    (lstat(ce->name, &st) < 0) ||
+		    is_empty_dir(name))
+			continue;
+
+		if (!submodule_uses_gitfile(name))
+			errs = error(_("submodule '%s' (or one of its nested "
+				     "submodules) uses a .git directory\n"
+				     "(use 'rm -rf' if you really want to remove "
+				     "it including all of its history)"), name);
+	}
+
+	return errs;
+}
+
 static int check_local_mod(unsigned char *head, int index_only)
 {
 	/*
