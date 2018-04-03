 	}
 
 	real_ref = NULL;
-	if (get_sha1(start_name, sha1))
+	if (get_sha1(start_name, sha1)) {
+		if (explicit_tracking)
+			die(_(upstream_missing));
 		die("Not a valid object name: '%s'.", start_name);
+	}
 
 	switch (dwim_ref(start_name, strlen(start_name), sha1, &real_ref)) {
 	case 0: