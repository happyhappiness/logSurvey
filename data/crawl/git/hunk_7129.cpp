 	 * "From " and having something that looks like a date format.
 	 */
 	for (;;) {
-		int is_partial = (buf[len-1] != '\n');
+		int is_partial = len && buf[len-1] != '\n';
 
-		if (fputs(buf, output) == EOF)
+		if (fwrite(buf, 1, len, output) != len)
 			die("cannot write output");
 
-		if (fgets(buf, sizeof(buf), mbox) == NULL) {
+		len = read_line_with_nul(buf, sizeof(buf), mbox);
+		if (len == 0) {
 			if (feof(mbox)) {
 				status = 1;
 				break;
 			}
 			die("cannot read mbox");
 		}
-		len = strlen(buf);
 		if (!is_partial && !is_bare && is_from_line(buf, len))
 			break; /* done with one message */
 	}
