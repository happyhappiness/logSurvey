 		ecb.priv = &data;
 		xdi_diff(&mf1, &mf2, &xpp, &xecfg, &ecb);
 
-		if ((data.ws_rule & WS_BLANK_AT_EOF) &&
-		    data.trailing_blanks_start) {
-			static char *err;
-
-			if (!err)
-				err = whitespace_error_string(WS_BLANK_AT_EOF);
-			fprintf(o->file, "%s:%d: %s\n",
-				data.filename, data.trailing_blanks_start, err);
-			data.status = 1; /* report errors */
+		if (data.ws_rule & WS_BLANK_AT_EOF) {
+			int blank_at_eof = adds_blank_at_eof(&mf1, &mf2, data.ws_rule);
+			if (blank_at_eof) {
+				static char *err;
+				if (!err)
+					err = whitespace_error_string(WS_BLANK_AT_EOF);
+				fprintf(o->file, "%s:%d: %s.\n",
+					data.filename, blank_at_eof, err);
+				data.status = 1; /* report errors */
+			}
 		}
 	}
  free_and_return:
