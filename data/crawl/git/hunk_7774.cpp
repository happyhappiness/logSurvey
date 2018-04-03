 		}
 		if (!memcmp(line, "ok", 2))
 			continue;
-		fputs(line, stderr);
+		if (hint)
+			hint = set_ref_error(hint, line + 3);
+		if (!hint)
+			hint = set_ref_error(refs, line + 3);
 		ret = -1;
 	}
 	return ret;
