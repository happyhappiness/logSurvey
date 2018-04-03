 			return;
 		}
 		diff_words_flush(ecbdata);
-		line++;
-		len--;
-		emit_line(ecbdata->file, plain, reset, line, len);
+		if (ecbdata->diff_words->type == DIFF_WORDS_PORCELAIN) {
+			emit_line(ecbdata->file, plain, reset, line, len);
+			fputs("~\n", ecbdata->file);
+		} else {
+			/* don't print the prefix character */
+			emit_line(ecbdata->file, plain, reset, line+1, len-1);
+		}
 		return;
 	}
 
