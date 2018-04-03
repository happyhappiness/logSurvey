 		struct diffstat_file *file = data->files[i];
 
 		if (file->is_binary)
-			printf("-\t-\t");
+			fprintf(options->file, "-\t-\t");
 		else
-			printf("%d\t%d\t", file->added, file->deleted);
+			fprintf(options->file,
+				"%d\t%d\t", file->added, file->deleted);
 		if (options->line_termination) {
 			fill_print_name(file);
 			if (!file->is_renamed)
-				write_name_quoted(file->name, stdout,
+				write_name_quoted(file->name, options->file,
 						  options->line_termination);
 			else {
-				fputs(file->print_name, stdout);
-				putchar(options->line_termination);
+				fputs(file->print_name, options->file);
+				putc(options->line_termination, options->file);
 			}
 		} else {
 			if (file->is_renamed) {
-				putchar('\0');
-				write_name_quoted(file->from_name, stdout, '\0');
+				putc('\0', options->file);
+				write_name_quoted(file->from_name, options->file, '\0');
 			}
-			write_name_quoted(file->name, stdout, '\0');
+			write_name_quoted(file->name, options->file, '\0');
 		}
 	}
 }
