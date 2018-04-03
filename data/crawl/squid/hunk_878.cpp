 wordlistCat(const wordlist * w, MemBuf * mb)
 {
     while (NULL != w) {
-        mb->Printf("%s\n", w->key);
+        mb->appendf("%s\n", w->key);
         w = w->next;
     }
 }