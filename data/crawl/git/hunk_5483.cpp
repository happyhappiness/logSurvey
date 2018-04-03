 		nofirst = 0;
 	}
 
-	fputs(set, file);
-
-	if (!nofirst)
-		fputc(first, file);
-	fwrite(line, len, 1, file);
-	fputs(reset, file);
+	if (len || !nofirst) {
+		fputs(set, file);
+		if (!nofirst)
+			fputc(first, file);
+		fwrite(line, len, 1, file);
+		fputs(reset, file);
+	}
 	if (has_trailing_carriage_return)
 		fputc('\r', file);
 	if (has_trailing_newline)
