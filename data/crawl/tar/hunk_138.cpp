     }
 }
 
+static void
+sparse_map_decoder (struct tar_stat_info *st, char const *arg,
+		    size_t size __attribute__((unused)))
+{
+  int offset = 1;
+  static char *keyword = "GNU.sparse.map";
+  
+  st->sparse_map_avail = 0;
+  while (1)
+    {
+      uintmax_t u;
+      char *delim;
+      struct sp_array e;
+      
+      if (!ISDIGIT (*arg))
+	{
+	  ERROR ((0, 0, _("Malformed extended header: invalid %s=%s"),
+		  keyword, arg));
+	  return;
+	}
+
+      errno = 0;
+      u = strtoumax (arg, &delim, 10);
+      if (offset)
+	{
+	  e.offset = u;
+	  if (!(u == e.offset && errno != ERANGE))
+	    {
+	      out_of_range_header (keyword, arg, 0, TYPE_MAXIMUM (off_t));
+	      return;
+	    }
+	}
+      else
+	{
+	  e.numbytes = u;
+	  if (!(u == e.numbytes && errno != ERANGE))
+	    {
+	      out_of_range_header (keyword, arg, 0, TYPE_MAXIMUM (size_t));
+	      return;
+	    }
+	  if (st->sparse_map_avail < st->sparse_map_size)
+	    st->sparse_map[st->sparse_map_avail++] = e;
+	  else
+	    {
+	      ERROR ((0, 0, _("Malformed extended header: excess %s=%s"),
+		      "GNU.sparse.numbytes", arg));
+	      return;
+	    }
+	}
+	    
+      offset = !offset;
+
+      if (*delim == 0)
+	break;
+      else if (*delim != ',')
+	{
+	  ERROR ((0, 0,
+		  _("Malformed extended header: invalid %s: unexpected delimiter %c"),
+		  keyword, *delim));
+	  return;
+	}
+
+      arg = delim + 1;
+    }
+
+  if (!offset)
+    ERROR ((0, 0,
+	    _("Malformed extended header: invalid %s: odd number of values"),
+	    keyword));
+}
+
+static void
+dumpdir_coder (struct tar_stat_info const *st, char const *keyword,
+	       struct xheader *xhdr, void *data)
+{
+  xheader_print_n (xhdr, keyword, data, dumpdir_size (data));
+}
+
+static void
+dumpdir_decoder (struct tar_stat_info *st, char const *arg,
+		 size_t size)
+{
+  st->dumpdir = xmalloc (size);
+  memcpy (st->dumpdir, arg, size);
+}
+
 struct xhdr_tab const xhdr_tab[] = {
   { "atime",	atime_coder,	atime_decoder,	  false },
   { "comment",	dummy_coder,	dummy_decoder,	  false },
