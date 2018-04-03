 	else
 		type = sha1_object_info(sha1, &size);
 
-	if (type <= 0)
-		return 1;
+	if (type <= 0) {
+		printf("%s missing\n", obj_name);
+		fflush(stdout);
+		return 0;
+	}
 
 	printf("%s %s %lu\n", sha1_to_hex(sha1), typename(type), size);
 	fflush(stdout);
