 	if (!ref)
 		return 1;
 
-	while (ref) {
-		if (check_ref_type(ref, flags))
-			printf("%s	%s\n", sha1_to_hex(ref->old_sha1), ref->name);
-		ref = ref->next;
+	for ( ; ref; ref = ref->next) {
+		if (!check_ref_type(ref, flags))
+			continue;
+		if (!tail_match(pattern, ref->name))
+			continue;
+		printf("%s	%s\n", sha1_to_hex(ref->old_sha1), ref->name);
 	}
 	return 0;
 }