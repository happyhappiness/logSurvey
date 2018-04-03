   lcc_connection_t *connection;
   lcc_identifier_t ident;
 
-  // Pointer which is passed to lcc_flush.
-  //Either a null pointer or it points to ident
+  /* Pointer which is passed to lcc_flush.
+   * Either a null pointer or it points to ident */
   lcc_identifier_t *identp;
   int status;
 
   connection = NULL;
   status = lcc_connect(address, &connection);
-  if (status != 0)
-  {
-		fprintf (stderr, "ERROR: Connecting to daemon at %s failed: %s.\n",
-				address, strerror (errno));
-		return 1;
-	}
+  if (status != 0) {
+    fprintf (stderr, "ERROR: Connecting to daemon at %s failed: %s.\n",
+        address, strerror (errno));
+    return 1;
+  }
 
   identp = NULL;
   if (ident_str != NULL && *ident_str != '\0') {
-    identp = &ident;
     status = lcc_string_to_identifier (connection, &ident, ident_str);
     if (status != 0) {
       fprintf (stderr, "ERROR: Creating and identifier failed: %s.\n",
