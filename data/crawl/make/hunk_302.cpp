 }
 
 
-/* Write a message in the child's context.  Write it to the child's output
-   sync file if present, otherwise to the terminal.  */
-
-static void
-child_out (const struct child *child, const char *msg, int out)
-{
-  int fd = out ? child->outfd : child->errfd;
-
-  if (!msg || msg[0] == '\0')
-    return;
-
-  if (fd >= 0)
-    {
-      int len = strlen (msg);
-      int b;
-
-      lseek (fd, 0, SEEK_END);
-      while (1)
-        {
-          EINTRLOOP (b, write (fd, msg, len));
-          if (b == len)
-            break;
-          if (b <= 0)
-            return;
-          len -= b;
-          msg += b;
-        }
-      EINTRLOOP (b, write (fd, "\n", 1));
-    }
-  else
-    {
-      FILE *f = out ? stdout : stderr;
-      fputs (msg, f);
-      putc ('\n', f);
-      fflush (f);
-    }
-}
-
 /* Write an error message describing the exit status given in
    EXIT_CODE, EXIT_SIG, and COREDUMP, for the target TARGET_NAME.
    Append "(ignored)" if IGNORED is nonzero.  */
 
 static void
-child_error (const struct child *child,
+child_error (struct child *child,
              int exit_code, int exit_sig, int coredump, int ignored)
 {
   const char *pre = "*** ";
