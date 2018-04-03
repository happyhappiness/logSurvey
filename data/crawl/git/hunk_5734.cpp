 		for_each_ref(get_name, NULL);
 	}
 
+	if (!found_names)
+		die("cannot describe '%s'", sha1_to_hex(sha1));
+
 	n = cmit->util;
 	if (n) {
 		/*