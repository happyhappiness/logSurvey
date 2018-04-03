 	o = variable_buffer_output (o, replace, rlen);
 
       /* Advance T past the string to be replaced.  */
-      {
-        char *nt = p + slen;
-        t = nt;
-      }
+      t = p + slen;
     } while (*t != '\0');
 
   return o;
