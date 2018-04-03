     cs->current_membuf = cs->membufs;
     cs->index.head = NULL;
     cs->index.tail = NULL;
+
+    parse_cachedir_options(sd, NULL, 0);
 }
 
 
 static void
 storeCossDirReconfigure(SwapDir * sd, int index, char *path)
 {
-    char *token;
     unsigned int i;
     unsigned int size;
-    unsigned int read_only = 0;
 
     i = GetInteger();
     size = i << 10;		/* Mbytes to Kbytes */
     if (size <= 0)
 	fatal("storeCossDirParse: invalid size value");
-    if ((token = strtok(NULL, w_space)))
-	if (!strcasecmp(token, "read-only"))
-	    read_only = 1;
 
     if (size == sd->max_size)
 	debug(3, 1) ("Cache COSS dir '%s' size remains unchanged at %d KB\n", path, size);
     else {
 	debug(3, 1) ("Cache COSS dir '%s' size changed to %d KB\n", path, size);
 	sd->max_size = size;
     }
-
-    if (read_only != sd->flags.read_only) {
-	debug(3, 1) ("Cache COSS dir '%s' now %s\n", path, read_only ? "Read-Only" : "Read-Write");
-	sd->flags.read_only = read_only;
-    }
+    parse_cachedir_options(sd, NULL, 1);
 }
 
 void
