 	trailer_start = find_trailer_start(lines, trailer_end);
 
 	/* Print lines before the trailers as is */
-	print_lines(lines, 0, trailer_start);
+	print_lines(outfile, lines, 0, trailer_start);
 
 	if (!has_blank_line_before(lines, trailer_start - 1))
-		printf("\n");
+		fprintf(outfile, "\n");
 
 	/* Parse trailer lines */
 	for (i = trailer_start; i < trailer_end; i++) {
