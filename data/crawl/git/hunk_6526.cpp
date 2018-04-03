 
 struct diff_words_data {
 	struct diff_words_buffer minus, plus;
+	const char *current_plus;
 	FILE *file;
 };
 
-static void print_word(FILE *file, struct diff_words_buffer *buffer, int len, int color,
-		int suppress_newline)
+static void fn_out_diff_words_aux(void *priv, char *line, unsigned long len)
 {
-	const char *ptr;
-	int eol = 0;
+	struct diff_words_data *diff_words = priv;
+	int minus_first, minus_len, plus_first, plus_len;
+	const char *minus_begin, *minus_end, *plus_begin, *plus_end;
 
-	if (len == 0)
+	if (line[0] != '@' || parse_hunk_header(line, len,
+			&minus_first, &minus_len, &plus_first, &plus_len))
 		return;
 
-	ptr  = buffer->text.ptr + buffer->current;
-	buffer->current += len;
+	/* POSIX requires that first be decremented by one if len == 0... */
+	if (minus_len) {
+		minus_begin = diff_words->minus.orig[minus_first].begin;
+		minus_end =
+			diff_words->minus.orig[minus_first + minus_len - 1].end;
+	} else
+		minus_begin = minus_end =
+			diff_words->minus.orig[minus_first].end;
 
-	if (ptr[len - 1] == '\n') {
-		eol = 1;
-		len--;
-	}
+	if (plus_len) {
+		plus_begin = diff_words->plus.orig[plus_first].begin;
+		plus_end = diff_words->plus.orig[plus_first + plus_len - 1].end;
+	} else
+		plus_begin = plus_end = diff_words->plus.orig[plus_first].end;
 
-	fputs(diff_get_color(1, color), file);
-	fwrite(ptr, len, 1, file);
-	fputs(diff_get_color(1, DIFF_RESET), file);
+	if (diff_words->current_plus != plus_begin)
+		fwrite(diff_words->current_plus,
+				plus_begin - diff_words->current_plus, 1,
+				diff_words->file);
+	if (minus_begin != minus_end)
+		color_fwrite_lines(diff_words->file,
+				diff_get_color(1, DIFF_FILE_OLD),
+				minus_end - minus_begin, minus_begin);
+	if (plus_begin != plus_end)
+		color_fwrite_lines(diff_words->file,
+				diff_get_color(1, DIFF_FILE_NEW),
+				plus_end - plus_begin, plus_begin);
 
-	if (eol) {
-		if (suppress_newline)
-			buffer->suppressed_newline = 1;
-		else
-			putc('\n', file);
-	}
-}
-
-static void fn_out_diff_words_aux(void *priv, char *line, unsigned long len)
-{
-	struct diff_words_data *diff_words = priv;
-
-	if (diff_words->minus.suppressed_newline) {
-		if (line[0] != '+')
-			putc('\n', diff_words->file);
-		diff_words->minus.suppressed_newline = 0;
-	}
-
-	len--;
-	switch (line[0]) {
-		case '-':
-			print_word(diff_words->file,
-				   &diff_words->minus, len, DIFF_FILE_OLD, 1);
-			break;
-		case '+':
-			print_word(diff_words->file,
-				   &diff_words->plus, len, DIFF_FILE_NEW, 0);
-			break;
-		case ' ':
-			print_word(diff_words->file,
-				   &diff_words->plus, len, DIFF_PLAIN, 0);
-			diff_words->minus.current += len;
-			break;
-	}
+	diff_words->current_plus = plus_end;
 }
 
 /*
- * This function splits the words in buffer->text, and stores the list with
- * newline separator into out.
+ * This function splits the words in buffer->text, stores the list with
+ * newline separator into out, and saves the offsets of the original words
+ * in buffer->orig.
  */
 static void diff_words_fill(struct diff_words_buffer *buffer, mmfile_t *out)
 {
-	int i;
-	out->size = buffer->text.size;
-	out->ptr = xmalloc(out->size);
-	memcpy(out->ptr, buffer->text.ptr, out->size);
-	for (i = 0; i < out->size; i++)
-		if (isspace(out->ptr[i]))
-			out->ptr[i] = '\n';
-	buffer->current = 0;
+	int i, j;
+
+	out->size = 0;
+	out->ptr = xmalloc(buffer->text.size);
+
+	/* fake an empty "0th" word */
+	ALLOC_GROW(buffer->orig, 1, buffer->orig_alloc);
+	buffer->orig[0].begin = buffer->orig[0].end = buffer->text.ptr;
+	buffer->orig_nr = 1;
+
+	for (i = 0; i < buffer->text.size; i++) {
+		if (isspace(buffer->text.ptr[i]))
+			continue;
+		for (j = i + 1; j < buffer->text.size &&
+				!isspace(buffer->text.ptr[j]); j++)
+			; /* find the end of the word */
+
+		/* store original boundaries */
+		ALLOC_GROW(buffer->orig, buffer->orig_nr + 1,
+				buffer->orig_alloc);
+		buffer->orig[buffer->orig_nr].begin = buffer->text.ptr + i;
+		buffer->orig[buffer->orig_nr].end = buffer->text.ptr + j;
+		buffer->orig_nr++;
+
+		/* store one word */
+		memcpy(out->ptr + out->size, buffer->text.ptr + i, j - i);
+		out->ptr[out->size + j - i] = '\n';
+		out->size += j - i + 1;
+
+		i = j - 1;
+	}
 }
 
 /* this executes the word diff on the accumulated buffers */
