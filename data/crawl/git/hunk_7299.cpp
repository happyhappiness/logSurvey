 			del = scale_linear(del, width, max_change);
 			total = add + del;
 		}
-		show_name(prefix, name, len, reset, set);
-		printf("%5d ", added + deleted);
-		show_graph('+', add, add_c, reset);
-		show_graph('-', del, del_c, reset);
-		putchar('\n');
-	}
-	printf("%s %d files changed, %d insertions(+), %d deletions(-)%s\n",
+		show_name(options->file, prefix, name, len, reset, set);
+		fprintf(options->file, "%5d ", added + deleted);
+		show_graph(options->file, '+', add, add_c, reset);
+		show_graph(options->file, '-', del, del_c, reset);
+		fprintf(options->file, "\n");
+	}
+	fprintf(options->file,
+	       "%s %d files changed, %d insertions(+), %d deletions(-)%s\n",
 	       set, total_files, adds, dels, reset);
 }
 
-static void show_shortstats(struct diffstat_t* data)
+static void show_shortstats(struct diffstat_t* data, struct diff_options *options)
 {
 	int i, adds = 0, dels = 0, total_files = data->nr;
 
