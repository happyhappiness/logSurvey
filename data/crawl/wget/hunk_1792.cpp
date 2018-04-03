   /* Disallow embedded newlines.  */
   if (strchr (val, '\n'))
     {
-      fprintf (stderr, _("%s: %s: Invalid value `%s'.\n"),
-               exec_name, com, val);
+      fprintf (stderr, _("%s: %s: Invalid value %s.\n"),
+               exec_name, com, quote (val));
       return false;
     }
   xfree_null (opt.useragent);
 src/ChangeLog | 1 +
 src/log.c     | 4 ++--
 2 files changed, 3 insertions(+), 2 deletions(-)
