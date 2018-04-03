 			total = add + del;
 		}
 		show_name(options->file, prefix, name, len, reset, set);
-		fprintf(options->file, "%5d ", added + deleted);
+		fprintf(options->file, "%5d%s", added + deleted,
+				added + deleted ? " " : "");
 		show_graph(options->file, '+', add, add_c, reset);
 		show_graph(options->file, '-', del, del_c, reset);
 		fprintf(options->file, "\n");
