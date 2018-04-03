 			printf("-\t-\t");
 		else
 			printf("%d\t%d\t", file->added, file->deleted);
-		if (options->line_termination && !file->is_renamed &&
-		    quote_c_style(file->name, NULL, NULL, 0))
-			quote_c_style(file->name, NULL, stdout, 0);
-		else
+		if (!file->is_renamed) {
+			write_name_quoted(file->name, stdout, options->line_termination);
+		} else {
 			fputs(file->name, stdout);
-		putchar(options->line_termination);
+			putchar(options->line_termination);
+		}
 	}
 }
 
