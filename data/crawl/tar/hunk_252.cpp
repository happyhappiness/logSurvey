   char buf[UINTMAX_STRSIZE_BOUND];
   int e = errno;
   ERROR ((0, e,
-	  _("%s: Read error at byte %s, reading %lu bytes"),
+	  ngettext ("%s: Read error at byte %s, reading %lu byte",
+		    "%s: Read error at byte %s, reading %lu bytes",
+		    size),
 	  quotearg_colon (name), STRINGIFY_BIGINT (offset, buf),
 	  (unsigned long) size));
 }
