     assert (range->elength >= 0);
 
     if (!known_spec(range->elength))
-        packerPrintf(p, "/*");
+        p->Printf("/*");
     else
-        packerPrintf(p, "/%" PRId64, range->elength);
+        p->Printf("/%" PRId64, range->elength);
 }
 
 void
