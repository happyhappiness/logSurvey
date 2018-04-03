       if (end == 0)
 	end = s + strlen (s);
 
-      printf ("\t%.*s\n", end - s, s);
+      printf ("\t%.*s\n", (int) (end - s), s);
 
       s = end;
     }
