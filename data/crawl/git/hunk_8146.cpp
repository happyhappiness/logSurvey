 		}
 	}
 
-	if (fgetc(stdin) != '\n')
-		die("An lf did not trail the binary data as expected.");
-
+	skip_optional_lf();
 	*size = length;
 	return buffer;
 }
