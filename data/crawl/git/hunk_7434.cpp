 }
 
 
+static const char *get_oneline_for_filename(struct commit *commit,
+					    int keep_subject)
+{
+	static char filename[PATH_MAX];
+	char *sol;
+	int len = 0;
+	int suffix_len = strlen(fmt_patch_suffix) + 1;
+
+	sol = strstr(commit->buffer, "\n\n");
+	if (!sol)
+		filename[0] = '\0';
+	else {
+		int j, space = 0;
+
+		sol += 2;
+		/* strip [PATCH] or [PATCH blabla] */
+		if (!keep_subject && !prefixcmp(sol, "[PATCH")) {
+			char *eos = strchr(sol + 6, ']');
+			if (eos) {
+				while (isspace(*eos))
+					eos++;
+				sol = eos;
+			}
+		}
+
+		for (j = 0;
+		     j < FORMAT_PATCH_NAME_MAX - suffix_len - 5 &&
+			     len < sizeof(filename) - suffix_len &&
+			     sol[j] && sol[j] != '\n';
+		     j++) {
+			if (istitlechar(sol[j])) {
+				if (space) {
+					filename[len++] = '-';
+					space = 0;
+				}
+				filename[len++] = sol[j];
+				if (sol[j] == '.')
+					while (sol[j + 1] == '.')
+						j++;
+			} else
+				space = 1;
+		}
+		while (filename[len - 1] == '.'
+		       || filename[len - 1] == '-')
+			len--;
+		filename[len] = '\0';
+	}
+	return filename;
+}
+
 static FILE *realstdout = NULL;
 static const char *output_directory = NULL;
 
-static int reopen_stdout(struct commit *commit, int nr, int keep_subject,
-			 int numbered_files)
+static int reopen_stdout(const char *oneline, int nr, int total)
 {
 	char filename[PATH_MAX];
-	char *sol;
 	int len = 0;
 	int suffix_len = strlen(fmt_patch_suffix) + 1;
 
 	if (output_directory) {
-		if (strlen(output_directory) >=
+		len = snprintf(filename, sizeof(filename), "%s",
+				output_directory);
+		if (len >=
 		    sizeof(filename) - FORMAT_PATCH_NAME_MAX - suffix_len)
 			return error("name of output directory is too long");
-		strlcpy(filename, output_directory, sizeof(filename) - suffix_len);
-		len = strlen(filename);
 		if (filename[len - 1] != '/')
 			filename[len++] = '/';
 	}
 
-	if (numbered_files) {
-		sprintf(filename + len, "%d", nr);
-		len = strlen(filename);
-
-	} else {
-		sprintf(filename + len, "%04d", nr);
-		len = strlen(filename);
-
-		sol = strstr(commit->buffer, "\n\n");
-		if (sol) {
-			int j, space = 1;
-
-			sol += 2;
-			/* strip [PATCH] or [PATCH blabla] */
-			if (!keep_subject && !prefixcmp(sol, "[PATCH")) {
-				char *eos = strchr(sol + 6, ']');
-				if (eos) {
-					while (isspace(*eos))
-						eos++;
-					sol = eos;
-				}
-			}
-
-			for (j = 0;
-			     j < FORMAT_PATCH_NAME_MAX - suffix_len - 5 &&
-				     len < sizeof(filename) - suffix_len &&
-				     sol[j] && sol[j] != '\n';
-			     j++) {
-				if (istitlechar(sol[j])) {
-					if (space) {
-						filename[len++] = '-';
-						space = 0;
-					}
-					filename[len++] = sol[j];
-					if (sol[j] == '.')
-						while (sol[j + 1] == '.')
-							j++;
-				} else
-					space = 1;
-			}
-			while (filename[len - 1] == '.'
-			       || filename[len - 1] == '-')
-				len--;
-			filename[len] = 0;
-		}
-		if (len + suffix_len >= sizeof(filename))
-			return error("Patch pathname too long");
+	if (!oneline)
+		len += sprintf(filename + len, "%d", nr);
+	else {
+		len += sprintf(filename + len, "%04d-", nr);
+		len += snprintf(filename + len, sizeof(filename) - len - 1
+				- suffix_len, "%s", oneline);
 		strcpy(filename + len, fmt_patch_suffix);
 	}
 
