 	  else
 	    printf ("%s[%u]: ", program, makelevel);
 	}
-      VA_START (args, fmt);
-      VA_PRINTF (stdout, fmt, args);
-      VA_END (args);
+      va_start (args, fmt);
+      vfprintf (stdout, fmt, args);
+      va_end (args);
       putchar ('\n');
 
       if (output_sync)
