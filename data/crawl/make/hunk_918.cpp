      another special case where function arguments aren't broken up,
      just create a format string that puts them back together.  */
   for (len=0, argvp=argv; *argvp != 0; ++argvp)
-    len += strlen(*argvp) + 2;
+    len += strlen (*argvp) + 2;
 
   p = msg = alloca (len + 1);
 
   for (argvp=argv; argvp[1] != 0; ++argvp)
     {
-      strcpy(p, *argvp);
-      p += strlen(*argvp);
+      strcpy (p, *argvp);
+      p += strlen (*argvp);
       *(p++) = ',';
       *(p++) = ' ';
     }
-  strcpy(p, *argvp);
+  strcpy (p, *argvp);
 
   if (*funcname == 'e')
     fatal (reading_file, "%s", msg);
