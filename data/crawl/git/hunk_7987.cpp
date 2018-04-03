 	return -1;
 }
 
-void write_name_quoted(const char *prefix, int prefix_len,
-		       const char *name, int quote, FILE *out)
-{
-	int needquote;
-
-	if (!quote) {
-	no_quote:
-		if (prefix_len)
-			fprintf(out, "%.*s", prefix_len, prefix);
-		fputs(name, out);
-		return;
-	}
-
-	needquote = 0;
-	if (prefix_len)
-		needquote = quote_c_style_counted(prefix, prefix_len,
-						  NULL, NULL, 0);
-	if (!needquote)
-		needquote = quote_c_style(name, NULL, NULL, 0);
-	if (needquote) {
-		fputc('"', out);
-		if (prefix_len)
-			quote_c_style_counted(prefix, prefix_len,
-					      NULL, out, 1);
-		quote_c_style(name, NULL, out, 1);
-		fputc('"', out);
-	}
-	else
-		goto no_quote;
-}
-
 /* quoting as a string literal for other languages */
 
 void perl_quote_print(FILE *stream, const char *src)
