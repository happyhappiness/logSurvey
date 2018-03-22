 }
 
 void
-symlink_error (char const *contents, char const *name)
-{
-  int e = errno;
-  ERROR ((0, e, _("%s: Cannot create symlink to %s"),
-	  quotearg_colon (name), quote_n (1, contents)));
-}
-
-void
-stat_fatal (char const *name)
-{
-  call_arg_fatal ("stat", name);
-}
-
-void
-stat_error (char const *name)
-{
-  call_arg_error ("stat", name);
-}
-
-void
-stat_warn (char const *name)
-{
-  call_arg_warn ("stat", name);
-}
-
-void
 stat_diag (char const *name)
 {
   if (ignore_failed_read_option)
