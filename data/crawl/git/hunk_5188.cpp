 	return 0;
 }
 
+static enum eol determine_output_conversion(enum action action) {
+	switch (action) {
+	case CRLF_BINARY:
+		return EOL_UNSET;
+	case CRLF_CRLF:
+		return EOL_CRLF;
+	case CRLF_INPUT:
+		return EOL_LF;
+	case CRLF_GUESS:
+		if (!auto_crlf)
+			return EOL_UNSET;
+		/* fall through */
+	case CRLF_TEXT:
+	case CRLF_AUTO:
+		if (auto_crlf == AUTO_CRLF_TRUE)
+			return EOL_CRLF;
+		else if (auto_crlf == AUTO_CRLF_INPUT)
+			return EOL_LF;
+		else if (eol == EOL_UNSET)
+			return EOL_NATIVE;
+	}
+	return eol;
+}
+
 static void check_safe_crlf(const char *path, enum action action,
                             struct text_stat *stats, enum safe_crlf checksafe)
 {
 	if (!checksafe)
 		return;
 
-	if (action == CRLF_INPUT ||
-	    (action == CRLF_GUESS && auto_crlf == AUTO_CRLF_INPUT)) {
+	if (determine_output_conversion(action) == EOL_LF) {
 		/*
 		 * CRLFs would not be restored by checkout:
 		 * check if we'd remove CRLFs
 		 */
 		if (stats->crlf) {
 			if (checksafe == SAFE_CRLF_WARN)
-				warning("CRLF will be replaced by LF in %s.", path);
+				warning("CRLF will be replaced by LF in %s.\nThe file will have its original line endings in your working directory.", path);
 			else /* i.e. SAFE_CRLF_FAIL */
 				die("CRLF would be replaced by LF in %s.", path);
 		}
-	} else if (action == CRLF_CRLF ||
-		   (action == CRLF_GUESS && auto_crlf == AUTO_CRLF_TRUE)) {
+	} else if (determine_output_conversion(action) == EOL_CRLF) {
 		/*
 		 * CRLFs would be added by checkout:
 		 * check if we have "naked" LFs
 		 */
 		if (stats->lf != stats->crlf) {
 			if (checksafe == SAFE_CRLF_WARN)
-				warning("LF will be replaced by CRLF in %s", path);
+				warning("LF will be replaced by CRLF in %s.\nThe file will have its original line endings in your working directory.", path);
 			else /* i.e. SAFE_CRLF_FAIL */
 				die("LF would be replaced by CRLF in %s", path);
 		}
