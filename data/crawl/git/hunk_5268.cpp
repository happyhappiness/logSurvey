 			del = scale_linear(del, width, max_change);
 		}
 		show_name(options->file, prefix, name, len);
-		fprintf(options->file, "%5d%s", added + deleted,
+		fprintf(options->file, "%5"PRIuMAX"%s", added + deleted,
 				added + deleted ? " " : "");
 		show_graph(options->file, '+', add, add_c, reset);
 		show_graph(options->file, '-', del, del_c, reset);
