 		if (patch->is_binary)
 			printf("-\t-\t");
 		else
-			printf("%d\t%d\t",
-			       patch->lines_added, patch->lines_deleted);
-		if (line_termination && quote_c_style(name, NULL, NULL, 0))
-			quote_c_style(name, NULL, stdout, 0);
-		else
-			fputs(name, stdout);
-		putchar(line_termination);
+			printf("%d\t%d\t", patch->lines_added, patch->lines_deleted);
+		write_name_quoted(name, stdout, line_termination);
 	}
 }
 
