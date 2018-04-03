     }
 
     if (other.size() != 0)
-        p->Printf((pcount ? ", " SQUIDSTRINGPH : SQUIDSTRINGPH),
-                     SQUIDSTRINGPRINT(other));
+        p->appendf((pcount ? ", " SQUIDSTRINGPH : SQUIDSTRINGPH), SQUIDSTRINGPRINT(other));
 }
 
 void
