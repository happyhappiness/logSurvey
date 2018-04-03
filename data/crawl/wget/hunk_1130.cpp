   if (!al)
     {
       logprintf (LOG_NOTQUIET,
-                 _("%s: unable to resolve host address `%s'\n"),
-                 exec_name, host);
+                 _("%s: unable to resolve host address %s\n"),
+                 exec_name, quote (host));
       return E_HOST;
     }
 
 src/ChangeLog | 1 +
 src/convert.c | 4 ++--
 2 files changed, 3 insertions(+), 2 deletions(-)
