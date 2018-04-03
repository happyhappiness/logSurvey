 		      int always, int allow_undefined, int name_only)
 {
 	const char *name;
-	const unsigned char *sha1 = obj->sha1;
+	const unsigned char *sha1 = get_object_hash(*obj);
 
 	if (!name_only)
 		printf("%s ", caller_name ? caller_name : sha1_to_hex(sha1));
