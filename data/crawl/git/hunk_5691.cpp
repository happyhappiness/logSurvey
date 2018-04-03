 		ecb.priv = &data;
 		xdi_diff(&mf1, &mf2, &xpp, &xecfg, &ecb);
 
-		if ((data.ws_rule & WS_TRAILING_SPACE) &&
+		if ((data.ws_rule & WS_BLANK_AT_EOF) &&
 		    data.trailing_blanks_start) {
-			fprintf(o->file, "%s:%d: ends with blank lines.\n",
-				data.filename, data.trailing_blanks_start);
+			static char *err;
+
+			if (!err)
+				err = whitespace_error_string(WS_BLANK_AT_EOF);
+			fprintf(o->file, "%s:%d: %s\n",
+				data.filename, data.trailing_blanks_start, err);
 			data.status = 1; /* report errors */
 		}
 	}
