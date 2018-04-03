       xfree (val);
       break;
     default:
-      fprintf (stderr, _("%s: Invalid --execute command `%s'\n"),
-               exec_name, opt);
+      fprintf (stderr, _("%s: Invalid --execute command %s\n"),
+               exec_name, quote (opt));
       exit (2);
     }
 }
