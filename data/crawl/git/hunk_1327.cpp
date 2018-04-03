  *   printf("%s -> %s", sha1_to_hex(one), sha1_to_hex(two));
  */
 extern char *sha1_to_hex_r(char *out, const unsigned char *sha1);
+extern char *oid_to_hex_r(char *out, const struct object_id *oid);
 extern char *sha1_to_hex(const unsigned char *sha1);	/* static buffer result! */
 extern char *oid_to_hex(const struct object_id *oid);	/* same static buffer as sha1_to_hex */
 
