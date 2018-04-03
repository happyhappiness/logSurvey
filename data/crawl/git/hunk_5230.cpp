 			line[0] = bytes - 26 + 'a' - 1;
 		encode_85(line + 1, cp, bytes);
 		cp = (char *) cp + bytes;
+		fprintf(file, "%s", prefix);
 		fputs(line, file);
 		fputc('\n', file);
 	}
-	fprintf(file, "\n");
+	fprintf(file, "%s\n", prefix);
 	free(data);
 }
 
-static void emit_binary_diff(FILE *file, mmfile_t *one, mmfile_t *two)
+static void emit_binary_diff(FILE *file, mmfile_t *one, mmfile_t *two, char *prefix)
 {
-	fprintf(file, "GIT binary patch\n");
-	emit_binary_diff_body(file, one, two);
-	emit_binary_diff_body(file, two, one);
+	fprintf(file, "%sGIT binary patch\n", prefix);
+	emit_binary_diff_body(file, one, two, prefix);
+	emit_binary_diff_body(file, two, one, prefix);
 }
 
 static void diff_filespec_load_driver(struct diff_filespec *one)
