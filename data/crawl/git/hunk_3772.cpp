 
 	real_ref = NULL;
 	if (get_sha1(start_name, sha1)) {
-		if (explicit_tracking)
+		if (explicit_tracking) {
+			if (advice_set_upstream_failure) {
+				error(_(upstream_missing), start_name);
+				advise(_(upstream_advice));
+				exit(1);
+			}
 			die(_(upstream_missing), start_name);
+		}
 		die("Not a valid object name: '%s'.", start_name);
 	}
 