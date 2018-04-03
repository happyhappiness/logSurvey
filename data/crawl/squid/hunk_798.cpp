     assert (range->elength >= 0);
 
     if (!known_spec(range->elength))
-        p->Printf("/*");
+        p->append("/*", 2);
     else
-        p->Printf("/%" PRId64, range->elength);
+        p->appendf("/%" PRId64, range->elength);
 }
 
 void
