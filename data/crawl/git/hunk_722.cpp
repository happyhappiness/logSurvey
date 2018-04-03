 
 	while (strbuf_getline(&line, stdin) != EOF) {
 		const char *arg;
-		unsigned char sha1[20];
+		struct object_id oid;
 
 		if (skip_prefix(line.buf, "append ", &arg)) {
-			if (get_sha1_hex(arg, sha1))
+			if (get_oid_hex(arg, &oid))
 				die("not a hexadecimal SHA1: %s", arg);
-			sha1_array_append(&array, sha1);
+			sha1_array_append(&array, oid.hash);
 		} else if (skip_prefix(line.buf, "lookup ", &arg)) {
-			if (get_sha1_hex(arg, sha1))
+			if (get_oid_hex(arg, &oid))
 				die("not a hexadecimal SHA1: %s", arg);
-			printf("%d\n", sha1_array_lookup(&array, sha1));
+			printf("%d\n", sha1_array_lookup(&array, oid.hash));
 		} else if (!strcmp(line.buf, "clear"))
 			sha1_array_clear(&array);
 		else if (!strcmp(line.buf, "for_each_unique"))