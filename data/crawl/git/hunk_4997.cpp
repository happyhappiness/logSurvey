 	return read_packed_sha1(sha1, type, size);
 }
 
+/*
+ * This function dies on corrupt objects; the callers who want to
+ * deal with them should arrange to call read_object() and give error
+ * messages themselves.
+ */
 void *read_sha1_file_repl(const unsigned char *sha1,
 			  enum object_type *type,
 			  unsigned long *size,
