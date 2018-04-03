 			fprintf(options->file, "-\t-\t");
 		else
 			fprintf(options->file,
-				"%d\t%d\t", file->added, file->deleted);
+				"%"PRIuMAX"\t%"PRIuMAX"\t",
+				file->added, file->deleted);
 		if (options->line_termination) {
 			fill_print_name(file);
 			if (!file->is_renamed)