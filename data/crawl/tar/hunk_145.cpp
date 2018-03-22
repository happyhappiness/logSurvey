   uintmax_t u;
   if (decode_num (&u, arg, SIZE_MAX, "GNU.sparse.numbytes"))
     {
-      if (st->sparse_map_avail == st->sparse_map_size)
-	st->sparse_map = x2nrealloc (st->sparse_map,
-				     &st->sparse_map_size,
-				     sizeof st->sparse_map[0]);
-      st->sparse_map[st->sparse_map_avail++].numbytes = u;
+      if (st->sparse_map_avail < st->sparse_map_size)
+	st->sparse_map[st->sparse_map_avail++].numbytes = u;
+      else
+	ERROR ((0, 0, _("Malformed extended header: excess %s=%s"),
+		"GNU.sparse.numbytes", arg));
     }
 }
 
