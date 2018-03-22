 }
 
 void
-savedir_error (char const *name)
-{
-  call_arg_error ("savedir", name);
-}
-
-void
-savedir_warn (char const *name)
-{
-  call_arg_warn ("savedir", name);
-}
-
-void
 savedir_diag (char const *name)
 {
   if (ignore_failed_read_option)
