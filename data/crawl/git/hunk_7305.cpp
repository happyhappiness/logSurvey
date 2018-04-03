 			line[0] = bytes - 26 + 'a' - 1;
 		encode_85(line + 1, cp, bytes);
 		cp = (char *) cp + bytes;
-		puts(line);
+		fputs(line, file);
+		fputc('\n', file);
 	}
-	printf("\n");
+	fprintf(file, "\n");
 	free(data);
 }
 
-static void emit_binary_diff(mmfile_t *one, mmfile_t *two)
+static void emit_binary_diff(FILE *file, mmfile_t *one, mmfile_t *two)
 {
-	printf("GIT binary patch\n");
-	emit_binary_diff_body(one, two);
-	emit_binary_diff_body(two, one);
+	fprintf(file, "GIT binary patch\n");
+	emit_binary_diff_body(file, one, two);
+	emit_binary_diff_body(file, two, one);
 }
 
 static void setup_diff_attr_check(struct git_attr_check *check)
