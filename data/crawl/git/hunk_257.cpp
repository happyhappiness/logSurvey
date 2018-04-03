 
 			errno = 0;
 			timestamp = parse_timestamp(str, &end, 10);
-			if (errno)
-				return error(_("invalid timestamp"));
+			if (errno) {
+				rc = error(_("invalid timestamp"));
+				goto exit;
+			}
 
-			if (!skip_prefix(end, " ", &str))
-				return error(_("invalid Date line"));
+			if (!skip_prefix(end, " ", &str)) {
+				rc = error(_("invalid Date line"));
+				goto exit;
+			}
 
 			errno = 0;
 			tz = strtol(str, &end, 10);
-			if (errno)
-				return error(_("invalid timezone offset"));
+			if (errno) {
+				rc = error(_("invalid timezone offset"));
+				goto exit;
+			}
 
-			if (*end)
-				return error(_("invalid Date line"));
+			if (*end) {
+				rc = error(_("invalid Date line"));
+				goto exit;
+			}
 
 			/*
 			 * mercurial's timezone is in seconds west of UTC,
