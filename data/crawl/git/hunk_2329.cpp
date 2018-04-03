 	return 0;
 }
 
-static void print_lines(struct strbuf **lines, int start, int end)
+static void print_lines(FILE *outfile, struct strbuf **lines, int start, int end)
 {
 	int i;
 	for (i = start; lines[i] && i < end; i++)
-		printf("%s", lines[i]->buf);
+		fprintf(outfile, "%s", lines[i]->buf);
 }
 
-static int process_input_file(struct strbuf **lines,
+static int process_input_file(FILE *outfile,
+			      struct strbuf **lines,
 			      struct trailer_item **in_tok_first,
 			      struct trailer_item **in_tok_last)
 {
