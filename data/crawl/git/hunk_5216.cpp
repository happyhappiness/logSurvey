 	} else
 		plus_begin = plus_end = diff_words->plus.orig[plus_first].end;
 
-	if (diff_words->current_plus != plus_begin)
-		fn_out_diff_words_write_helper(diff_words->file,
+	if (color_words_output_graph_prefix(diff_words)) {
+		fputs(line_prefix, diff_words->opt->file);
+	}
+	if (diff_words->current_plus != plus_begin) {
+		fn_out_diff_words_write_helper(diff_words->opt->file,
 				&style->ctx, style->newline,
 				plus_begin - diff_words->current_plus,
-				diff_words->current_plus);
-	if (minus_begin != minus_end)
-		fn_out_diff_words_write_helper(diff_words->file,
+				diff_words->current_plus, line_prefix);
+		if (*(plus_begin - 1) == '\n')
+			fputs(line_prefix, diff_words->opt->file);
+	}
+	if (minus_begin != minus_end) {
+		fn_out_diff_words_write_helper(diff_words->opt->file,
 				&style->old, style->newline,
-				minus_end - minus_begin, minus_begin);
-	if (plus_begin != plus_end)
-		fn_out_diff_words_write_helper(diff_words->file,
+				minus_end - minus_begin, minus_begin,
+				line_prefix);
+	}
+	if (plus_begin != plus_end) {
+		fn_out_diff_words_write_helper(diff_words->opt->file,
 				&style->new, style->newline,
-				plus_end - plus_begin, plus_begin);
+				plus_end - plus_begin, plus_begin,
+				line_prefix);
+	}
 
 	diff_words->current_plus = plus_end;
+	diff_words->last_minus = minus_first;
 }
 
 /* This function starts looking at *begin, and returns 0 iff a word was found. */
