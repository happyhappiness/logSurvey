 {
   uintmax_t u;
   if (decode_num (&u, arg, TYPE_MAXIMUM (off_t), "GNU.sparse.offset"))
-    st->sparse_map[st->sparse_map_avail].offset = u;
+    {
+      if (st->sparse_map_avail < st->sparse_map_size)
+	st->sparse_map[st->sparse_map_avail].offset = u;
+      else
+	ERROR ((0, 0, _("Malformed extended header: excess %s=%s"),
+		"GNU.sparse.offset", arg));
+    }
 }
 
 static void
 sparse_numbytes_coder (struct tar_stat_info const *st, char const *keyword,
 		     struct xheader *xhdr, void *data)
 {
-  size_t i = *(size_t*)data;
-  code_num (st->sparse_map[i].numbytes, keyword, xhdr);
+  size_t *pi = data;
+  code_num (st->sparse_map[*pi].numbytes, keyword, xhdr);
 }
 
 static void
