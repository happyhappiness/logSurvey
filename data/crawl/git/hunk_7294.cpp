 		len--;
 	}
 
-	fputs(diff_get_color(1, color), stdout);
-	fwrite(ptr, len, 1, stdout);
-	fputs(diff_get_color(1, DIFF_RESET), stdout);
+	fputs(diff_get_color(1, color), file);
+	fwrite(ptr, len, 1, file);
+	fputs(diff_get_color(1, DIFF_RESET), file);
 
 	if (eol) {
 		if (suppress_newline)
 			buffer->suppressed_newline = 1;
 		else
-			putchar('\n');
+			putc('\n', file);
 	}
 }
 
