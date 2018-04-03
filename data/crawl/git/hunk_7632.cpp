 			continue;
 		if (line[i] != '\t')
 			break;
-		if ((ws_rule & WS_SPACE_BEFORE_TAB) && written < i)
+		if ((ws_rule & WS_SPACE_BEFORE_TAB) && written < i) {
 			result |= WS_SPACE_BEFORE_TAB;
+			if (stream) {
+				fputs(ws, stream);
+				fwrite(line + written, i - written, 1, stream);
+				fputs(reset, stream);
+			}
+		} else if (stream)
+			fwrite(line + written, i - written, 1, stream);
+		if (stream)
+			fwrite(line + i, 1, 1, stream);
 		written = i + 1;
 	}
 
 	/* Check for indent using non-tab. */
-	if ((ws_rule & WS_INDENT_WITH_NON_TAB) && i - written >= 8)
+	if ((ws_rule & WS_INDENT_WITH_NON_TAB) && i - written >= 8) {
 		result |= WS_INDENT_WITH_NON_TAB;
-
-	if (stream) {
-		/* Highlight errors in leading whitespace. */
-		if ((result & WS_SPACE_BEFORE_TAB) ||
-		    (result & WS_INDENT_WITH_NON_TAB)) {
+		if (stream) {
 			fputs(ws, stream);
-			fwrite(line, written, 1, stream);
+			fwrite(line + written, i - written, 1, stream);
 			fputs(reset, stream);
 		}
+		written = i;
+	}
 
+	if (stream) {
 		/* Now the rest of the line starts at written.
 		 * The non-highlighted part ends at trailing_whitespace. */
 		if (trailing_whitespace == -1)