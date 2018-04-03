 					"warning: Log for '%.*s' only goes "
 					"back to %s.\n", len, str,
 					show_date(co_time, co_tz, DATE_RFC2822));
-			else
-				fprintf(stderr,
-					"warning: Log for '%.*s' only has "
-					"%d entries.\n", len, str, co_cnt);
+			else {
+				free(real_ref);
+				die("Log for '%.*s' only has %d entries.",
+				    len, str, co_cnt);
+			}
 		}
 	}
 