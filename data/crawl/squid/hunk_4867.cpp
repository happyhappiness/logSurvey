     fatal("not implemented 6");
 }
 
-const char *
-wordlistAdd(wordlist ** list, const char *key)
-{
-    while (*list)
-        list = &(*list)->next;
-
-    *list = static_cast<wordlist *>(memAllocate(MEM_WORDLIST));
-
-    (*list)->key = xstrdup(key);
-
-    (*list)->next = NULL;
-
-    return (*list)->key;
-}
-
-void
-wordlistDestroy(wordlist ** list)
-{
-    fatal("not implemented 8");
-}
-
 char *
 strtokFile(void)
 {
