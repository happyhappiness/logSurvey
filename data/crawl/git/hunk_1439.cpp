 		find_lno(line, ecbdata);
 		emit_hunk_header(ecbdata, line, len);
 		if (line[len-1] != '\n')
-			putc('\n', ecbdata->opt->file);
+			putc('\n', o->file);
 		return;
 	}
 
 	if (len < 1) {
-		emit_line(ecbdata->opt, reset, reset, line, len);
+		emit_line(o, reset, reset, line, len);
 		if (ecbdata->diff_words
 		    && ecbdata->diff_words->type == DIFF_WORDS_PORCELAIN)
-			fputs("~\n", ecbdata->opt->file);
+			fputs("~\n", o->file);
 		return;
 	}
 
