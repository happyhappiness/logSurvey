 		return;
 	}
 
-	if (len < 1) {
-		emit_line(o, reset, reset, line, len);
-		if (ecbdata->diff_words
-		    && ecbdata->diff_words->type == DIFF_WORDS_PORCELAIN)
-			fputs("~\n", o->file);
-		return;
-	}
-
 	if (ecbdata->diff_words) {
 		if (line[0] == '-') {
 			diff_words_append(line, len,