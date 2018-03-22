 }
 
 void
-read_fatal (char const *name)
-{
-  call_arg_fatal ("read", name);
-}
-
-void
-read_fatal_details (char const *name, off_t offset, size_t size)
-{
-  char buf[UINTMAX_STRSIZE_BOUND];
-  int e = errno;
-  FATAL_ERROR ((0, e,
-		ngettext ("%s: Read error at byte %s, reading %lu byte",
-			  "%s: Read error at byte %s, reading %lu bytes",
-			  size),
-		quotearg_colon (name), STRINGIFY_BIGINT (offset, buf),
-		(unsigned long) size));
-}
-
-void
-readlink_error (char const *name)
-{
-  call_arg_error ("readlink", name);
-}
-
-void
-readlink_warn (char const *name)
-{
-  call_arg_warn ("readlink", name);
-}
-
-void
 readlink_diag (char const *name)
 {
   if (ignore_failed_read_option)
