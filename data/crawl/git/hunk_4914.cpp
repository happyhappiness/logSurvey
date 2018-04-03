 	}
 
 	/* Check for indent using non-tab. */
-	if ((ws_rule & WS_INDENT_WITH_NON_TAB) && i - written >= 8) {
+	if ((ws_rule & WS_INDENT_WITH_NON_TAB) && i - written >= ws_tab_width(ws_rule)) {
 		result |= WS_INDENT_WITH_NON_TAB;
 		if (stream) {
 			fputs(ws, stream);
