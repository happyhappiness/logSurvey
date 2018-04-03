 }
 
 /*
- * Convert a partial SHA1 hex string to the corresponding partial SHA1 value.
- * - hex      - Partial SHA1 segment in ASCII hex format
- * - hex_len  - Length of above segment. Must be multiple of 2 between 0 and 40
- * - oid      - Partial SHA1 value is written here
- * Return 0 on success or -1 on error (invalid arguments or input not
- * in hex format).
+ * Read `len` pairs of hexadecimal digits from `hex` and write the
+ * values to `binary` as `len` bytes. Return 0 on success, or -1 if
+ * the input does not consist of hex digits).
  */
-static int get_oid_hex_segment(const char *hex, unsigned int hex_len,
-		unsigned char *oid)
+static int hex_to_bytes(unsigned char *binary, const char *hex, size_t len)
 {
-	unsigned int i, len = hex_len >> 1;
-	if (hex_len % 2 != 0)
-		return -1;
-	for (i = 0; i < len; i++) {
+	for (; len; len--, hex += 2) {
 		unsigned int val = (hexval(hex[0]) << 4) | hexval(hex[1]);
+
 		if (val & ~0xff)
 			return -1;
-		*oid++ = val;
-		hex += 2;
+		*binary++ = val;
 	}
 	return 0;
 }
