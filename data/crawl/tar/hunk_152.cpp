 }
 
 void
-read_error (char const *name)
-{
-  call_arg_error ("read", name);
-}
-
-void
-read_error_details (char const *name, off_t offset, size_t size)
-{
-  char buf[UINTMAX_STRSIZE_BOUND];
-  int e = errno;
-  ERROR ((0, e,
-	  ngettext ("%s: Read error at byte %s, while reading %lu byte",
-		    "%s: Read error at byte %s, while reading %lu bytes",
-		    size),
-	  quotearg_colon (name), STRINGIFY_BIGINT (offset, buf),
-	  (unsigned long) size));
-}
-
-void
-read_warn_details (char const *name, off_t offset, size_t size)
-{
-  char buf[UINTMAX_STRSIZE_BOUND];
-  int e = errno;
-  WARN ((0, e,
-	 ngettext ("%s: Warning: Read error at byte %s, while reading %lu byte",
-		   "%s: Warning: Read error at byte %s, while reading %lu bytes",
-		   size),
-	 quotearg_colon (name), STRINGIFY_BIGINT (offset, buf),
-	 (unsigned long) size));
-}
-
-void
 read_diag_details (char const *name, off_t offset, size_t size)
 {
   if (ignore_failed_read_option)
