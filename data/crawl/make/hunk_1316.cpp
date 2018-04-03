     }
 
   /* No `endef'!!  */
-  makefile_fatal (filename, lineno, "missing `endef', unterminated `define'");
+  fatal (flocp, "missing `endef', unterminated `define'");
 
   /* NOTREACHED */
-  return 0;
+  return;
 }
 
 /* Interpret conditional commands "ifdef", "ifndef", "ifeq",
