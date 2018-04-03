 	fclose(f);
 }
 
+static int git_pack_config(const char *k, const char *v)
+{
+	if (!strcmp(k, "pack.depth")) {
+		max_depth = git_config_int(k, v);
+		if (max_depth > MAX_DEPTH)
+			max_depth = MAX_DEPTH;
+		return 0;
+	}
+	if (!strcmp(k, "pack.compression")) {
+		int level = git_config_int(k, v);
+		if (level == -1)
+			level = Z_DEFAULT_COMPRESSION;
+		else if (level < 0 || level > Z_BEST_COMPRESSION)
+			die("bad pack compression level %d", level);
+		pack_compression_level = level;
+		pack_compression_seen = 1;
+		return 0;
+	}
+	return git_default_config(k, v);
+}
+
 static const char fast_import_usage[] =
 "git-fast-import [--date-format=f] [--max-pack-size=n] [--depth=n] [--active-branches=n] [--export-marks=marks.file]";
 
 int main(int argc, const char **argv)
 {
 	unsigned int i, show_stats = 1;
 
-	git_config(git_default_config);
+	git_config(git_pack_config);
+	if (!pack_compression_seen && core_compression_seen)
+		pack_compression_level = core_compression_level;
+
 	alloc_objects(object_entry_alloc);
 	strbuf_init(&command_buf, 0);
 	atom_table = xcalloc(atom_table_sz, sizeof(struct atom_str*));