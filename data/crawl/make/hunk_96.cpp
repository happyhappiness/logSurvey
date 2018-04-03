 
   OUTPUT_SET (&child->output);
 
-  message (0, l + strlen (nm),
-           _("%s: recipe for target '%s' failed"), nm, f->name);
-
   l += strlen (pre) + strlen (post);
 
   if (exit_sig == 0)
     error (NILF, l + INTSTR_LENGTH,
-           _("%s[%s] Error %d%s"), pre, f->name, exit_code, post);
+           _("%s[%s: %s] Error %d%s"), pre, nm, f->name, exit_code, post);
   else
     {
       const char *s = strsignal (exit_sig);
       error (NILF, l + strlen (s) + strlen (dump),
-             _("%s[%s] %s%s%s"), pre, f->name, s, dump, post);
+             "%s[%s: %s] %s%s%s", pre, nm, f->name, s, dump, post);
     }
 
   OUTPUT_UNSET ();
