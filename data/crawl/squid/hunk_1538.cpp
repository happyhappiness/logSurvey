     if (!maximum)
         return sl;
     SBuf s;
-    s.Printf("%lu", (unsigned long int) maximum);
+    s.Printf("%d", maximum);
     sl.push_back(s);
     return sl;
 }
