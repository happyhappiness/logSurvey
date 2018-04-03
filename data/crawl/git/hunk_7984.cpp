 	else if (fmt & (DIFF_FORMAT_RAW | DIFF_FORMAT_NAME_STATUS))
 		diff_flush_raw(p, opt);
 	else if (fmt & DIFF_FORMAT_NAME)
-		diff_flush_name(p, opt);
+		write_name_quoted(p->two->path, stdout, opt->line_termination);
 }
 
 static void show_file_mode_name(const char *newdelete, struct diff_filespec *fs)
 {
-	char *name = quote_one(fs->path);
 	if (fs->mode)
-		printf(" %s mode %06o %s\n", newdelete, fs->mode, name);
+		printf(" %s mode %06o ", newdelete, fs->mode);
 	else
-		printf(" %s %s\n", newdelete, name);
-	free(name);
+		printf(" %s ", newdelete);
+	write_name_quoted(fs->path, stdout, '\n');
 }
 
 
 static void show_mode_change(struct diff_filepair *p, int show_name)
 {
 	if (p->one->mode && p->two->mode && p->one->mode != p->two->mode) {
+		printf(" mode change %06o => %06o%c", p->one->mode, p->two->mode,
+			show_name ? ' ' : '\n');
 		if (show_name) {
-			char *name = quote_one(p->two->path);
-			printf(" mode change %06o => %06o %s\n",
-			       p->one->mode, p->two->mode, name);
-			free(name);
+			write_name_quoted(p->two->path, stdout, '\n');
 		}
-		else
-			printf(" mode change %06o => %06o\n",
-			       p->one->mode, p->two->mode);
 	}
 }
 
