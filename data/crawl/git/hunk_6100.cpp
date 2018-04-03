 			add = scale_linear(add, width, max_change);
 			del = scale_linear(del, width, max_change);
 		}
-		show_name(options->file, prefix, name, len, reset, set);
+		show_name(options->file, prefix, name, len);
 		fprintf(options->file, "%5d%s", added + deleted,
 				added + deleted ? " " : "");
 		show_graph(options->file, '+', add, add_c, reset);
 		show_graph(options->file, '-', del, del_c, reset);
 		fprintf(options->file, "\n");
 	}
 	fprintf(options->file,
-	       "%s %d files changed, %d insertions(+), %d deletions(-)%s\n",
-	       set, total_files, adds, dels, reset);
+	       " %d files changed, %d insertions(+), %d deletions(-)\n",
+	       total_files, adds, dels);
 }
 
 static void show_shortstats(struct diffstat_t* data, struct diff_options *options)