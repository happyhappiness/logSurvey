 {
 	int i;
 
+	if (data->nr == 0)
+		return;
+
 	for (i = 0; i < data->nr; i++) {
 		struct diffstat_file *file = data->files[i];
 
 		if (file->is_binary)
 			printf("-\t-\t");
 		else
 			printf("%d\t%d\t", file->added, file->deleted);
-		if (!file->is_renamed) {
-			write_name_quoted(file->name, stdout, options->line_termination);
+		if (options->line_termination) {
+			fill_print_name(file);
+			if (!file->is_renamed)
+				write_name_quoted(file->name, stdout,
+						  options->line_termination);
+			else {
+				fputs(file->print_name, stdout);
+				putchar(options->line_termination);
+			}
 		} else {
-			fputs(file->name, stdout);
-			putchar(options->line_termination);
+			if (file->is_renamed) {
+				putchar('\0');
+				write_name_quoted(file->from_name, stdout, '\0');
+			}
+			write_name_quoted(file->name, stdout, '\0');
 		}
 	}
 }
 
+static void free_diffstat_info(struct diffstat_t *diffstat)
+{
+	int i;
+	for (i = 0; i < diffstat->nr; i++) {
+		struct diffstat_file *f = diffstat->files[i];
+		if (f->name != f->print_name)
+			free(f->print_name);
+		free(f->name);
+		free(f->from_name);
+		free(f);
+	}
+	free(diffstat->files);
+}
+
 struct checkdiff_t {
 	struct xdiff_emit_state xm;
 	const char *filename;
