 				fputs(ws, stream);
 				fwrite(line + written, i - written, 1, stream);
 				fputs(reset, stream);
+				fwrite(line + i, 1, 1, stream);
 			}
-		} else if (stream)
-			fwrite(line + written, i - written, 1, stream);
-		if (stream)
-			fwrite(line + i, 1, 1, stream);
+		} else if (ws_rule & WS_TAB_IN_INDENT) {
+			result |= WS_TAB_IN_INDENT;
+			if (stream) {
+				fwrite(line + written, i - written, 1, stream);
+				fputs(ws, stream);
+				fwrite(line + i, 1, 1, stream);
+				fputs(reset, stream);
+			}
+		} else if (stream) {
+			fwrite(line + written, i - written + 1, 1, stream);
+		}
 		written = i + 1;
 	}
 