 --------
 
 -----------------------------------------
-int print_callback(const unsigned char sha1[20],
+int print_callback(const struct object_id *oid,
 		    void *data)
 {
-	printf("%s\n", sha1_to_hex(sha1));
+	printf("%s\n", oid_to_hex(oid));
 	return 0; /* always continue */
 }
 
 void some_func(void)
 {
-	struct sha1_array hashes = SHA1_ARRAY_INIT;
-	unsigned char sha1[20];
+	struct sha1_array hashes = OID_ARRAY_INIT;
+	struct object_id oid;
 
 	/* Read objects into our set */
-	while (read_object_from_stdin(sha1))
-		sha1_array_append(&hashes, sha1);
+	while (read_object_from_stdin(oid.hash))
+		oid_array_append(&hashes, &oid);
 
 	/* Check if some objects are in our set */
-	while (read_object_from_stdin(sha1)) {
-		if (sha1_array_lookup(&hashes, sha1) >= 0)
+	while (read_object_from_stdin(oid.hash)) {
+		if (oid_array_lookup(&hashes, &oid) >= 0)
 			printf("it's in there!\n");
 
 	/*