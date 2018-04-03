 	el->filebuf = NULL;
 }
 
-static void check_trailing_spaces(const char *fname, char *buf)
+static void trim_trailing_spaces(char *buf)
 {
-	int i, last_space = -1, len = strlen(buf);
+	int i, last_space = -1, nr_spaces, len = strlen(buf);
 	for (i = 0; i < len; i++)
 		if (buf[i] == '\\')
 			i++;
-		else if (buf[i] == ' ')
-			last_space = i;
-		else
+		else if (buf[i] == ' ') {
+			if (last_space == -1) {
+				last_space = i;
+				nr_spaces = 1;
+			} else
+				nr_spaces++;
+		} else
 			last_space = -1;
 
-	if (last_space == len - 1)
-		warning(_("%s: trailing spaces in '%s'. Please quote or remove them."),
-			fname, buf);
+	if (last_space != -1 && last_space + nr_spaces == len)
+		buf[last_space] = '\0';
 }
 
 int add_excludes_from_file_to_list(const char *fname,
