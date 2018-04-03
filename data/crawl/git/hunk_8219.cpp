  * Remove empty lines from the beginning and end
  * and also trailing spaces from every line.
  *
+ * Note that the buffer will not be NUL-terminated.
+ *
  * Turn multiple consecutive empty lines between paragraphs
  * into just one empty line.
  *
  * If the input has only empty lines and spaces,
  * no output will be produced.
  *
+ * If last line has a newline at the end, it will be removed.
+ *
  * Enable skip_comments to skip every line starting with "#".
  */
-void stripspace(FILE *in, FILE *out, int skip_comments)
+size_t stripspace(char *buffer, size_t length, int skip_comments)
 {
 	int empties = -1;
-	int alloc = 1024;
-	char *line = xmalloc(alloc);
+	size_t i, j, len, newlen;
+	char *eol;
 
-	while (fgets(line, alloc, in)) {
-		int len = strlen(line);
+	for (i = j = 0; i < length; i += len, j += newlen) {
+		eol = memchr(buffer + i, '\n', length - i);
+		len = eol ? eol - (buffer + i) + 1 : length - i;
 
-		while (len == alloc - 1 && line[len - 1] != '\n') {
-			alloc = alloc_nr(alloc);
-			line = xrealloc(line, alloc);
-			fgets(line + len, alloc - len, in);
-			len += strlen(line + len);
-		}
-
-		if (skip_comments && line[0] == '#')
+		if (skip_comments && len && buffer[i] == '#') {
+			newlen = 0;
 			continue;
-		len = cleanup(line, len);
+		}
+		newlen = cleanup(buffer + i, len);
 
 		/* Not just an empty line? */
-		if (len) {
+		if (newlen) {
+			if (empties != -1)
+				buffer[j++] = '\n';
 			if (empties > 0)
-				fputc('\n', out);
+				buffer[j++] = '\n';
 			empties = 0;
-			fputs(line, out);
-			fputc('\n', out);
+			memmove(buffer + j, buffer + i, newlen);
 			continue;
 		}
 		if (empties < 0)
 			continue;
 		empties++;
 	}
-	free(line);
+
+	return j;
 }
 
 int cmd_stripspace(int argc, const char **argv, const char *prefix)
 {
-	stripspace(stdin, stdout, 0);
+	char *buffer;
+	unsigned long size;
+
+	size = 1024;
+	buffer = xmalloc(size);
+	if (read_pipe(0, &buffer, &size))
+		die("could not read the input");
+
+	size = stripspace(buffer, size, 0);
+	write_or_die(1, buffer, size);
+	if (size)
+		putc('\n', stdout);
+
+	free(buffer);
 	return 0;
 }
