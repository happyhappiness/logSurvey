 	}
 }
 
+struct diffstat_dir {
+	struct diffstat_file **files;
+	int nr, percent, cumulative;
+};
+
+static long gather_dirstat(struct diffstat_dir *dir, unsigned long changed, const char *base, int baselen)
+{
+	unsigned long this_dir = 0;
+	unsigned int sources = 0;
+
+	while (dir->nr) {
+		struct diffstat_file *f = *dir->files;
+		int namelen = strlen(f->name);
+		unsigned long this;
+		char *slash;
+
+		if (namelen < baselen)
+			break;
+		if (memcmp(f->name, base, baselen))
+			break;
+		slash = strchr(f->name + baselen, '/');
+		if (slash) {
+			int newbaselen = slash + 1 - f->name;
+			this = gather_dirstat(dir, changed, f->name, newbaselen);
+			sources++;
+		} else {
+			this = f->added + f->deleted;
+			dir->files++;
+			dir->nr--;
+			sources += 2;
+		}
+		this_dir += this;
+	}
+
+	/*
+	 * We don't report dirstat's for
+	 *  - the top level
+	 *  - or cases where everything came from a single directory
+	 *    under this directory (sources == 1).
+	 */
+	if (baselen && sources != 1) {
+		int permille = this_dir * 1000 / changed;
+		if (permille) {
+			int percent = permille / 10;
+			if (percent >= dir->percent) {
+				printf("%4d.%01d%% %.*s\n", percent, permille % 10, baselen, base);
+				if (!dir->cumulative)
+					return 0;
+			}
+		}
+	}
+	return this_dir;
+}
+
+static void show_dirstat(struct diffstat_t *data, struct diff_options *options)
+{
+	int i;
+	unsigned long changed;
+	struct diffstat_dir dir;
+
+	/* Calculate total changes */
+	changed = 0;
+	for (i = 0; i < data->nr; i++) {
+		changed += data->files[i]->added;
+		changed += data->files[i]->deleted;
+	}
+
+	/* This can happen even with many files, if everything was renames */
+	if (!changed)
+		return;
+
+	/* Show all directories with more than x% of the changes */
+	dir.files = data->files;
+	dir.nr = data->nr;
+	dir.percent = options->dirstat_percent;
+	dir.cumulative = options->output_format & DIFF_FORMAT_CUMULATIVE;
+	gather_dirstat(&dir, changed, "", 0);
+}
+
 static void free_diffstat_info(struct diffstat_t *diffstat)
 {
 	int i;
