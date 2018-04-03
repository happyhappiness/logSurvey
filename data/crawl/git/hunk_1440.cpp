 		}
 		diff_words_flush(ecbdata);
 		if (ecbdata->diff_words->type == DIFF_WORDS_PORCELAIN) {
-			emit_line(ecbdata->opt, context, reset, line, len);
-			fputs("~\n", ecbdata->opt->file);
+			emit_line(o, context, reset, line, len);
+			fputs("~\n", o->file);
 		} else {
 			/*
 			 * Skip the prefix character, if any.  With
