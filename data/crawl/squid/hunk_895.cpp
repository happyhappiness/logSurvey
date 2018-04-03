     }
 
     if (other.size() != 0)
-        packerPrintf(p, (pcount ? ", " SQUIDSTRINGPH : SQUIDSTRINGPH),
+        p->Printf((pcount ? ", " SQUIDSTRINGPH : SQUIDSTRINGPH),
                      SQUIDSTRINGPRINT(other));
 }
 
