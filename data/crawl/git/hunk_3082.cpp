 		mode->type = DATE_NORMAL;
 	else if (!strcmp(format, "raw"))
 		mode->type = DATE_RAW;
-	else
+	else if (skip_prefix(format, "format:", &format)) {
+		mode->type = DATE_STRFTIME;
+		mode->strftime_fmt = xstrdup(format);
+	} else
 		die("unknown date format %s", format);
 }
 
