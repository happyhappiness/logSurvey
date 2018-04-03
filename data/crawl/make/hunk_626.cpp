     {
       const char *end;
 
-      while (isspace ((unsigned char)*s))
-	++s;
-
       end = strchr (s, '\n');
       if (end == 0)
 	end = s + strlen (s);
 
-      printf ("\t%.*s\n", (int) (end - s), s);
+      printf ("%c%.*s\n", cmd_prefix, (int) (end - s), s);
 
-      s = end;
+      s = end + (end[0] == '\n');
     }
 }
