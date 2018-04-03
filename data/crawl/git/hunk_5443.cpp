 		} else if (0 <= nth)
 			at_time = 0;
 		else {
+			int errors = 0;
 			char *tmp = xstrndup(str + at + 2, reflog_len);
-			at_time = approxidate(tmp);
+			at_time = approxidate_careful(tmp, &errors);
+			if (errors)
+				die("Bogus timestamp '%s'", tmp);
 			free(tmp);
 		}
 		if (read_ref_at(real_ref, at_time, nth, sha1, NULL,
