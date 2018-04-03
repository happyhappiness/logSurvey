     return 0;
 }
 
-/*****************************************************************************
- * Max
- *****************************************************************************/
-
 static void
-dump_wordlist(StoreEntry * entry, wordlist *words)
+dump_SBufList(StoreEntry * entry, const SBufList &words)
 {
-    for (wordlist *word = words; word; word = word->next)
-        storeAppendPrintf(entry, "%s ", word->key);
+    for (SBufList::const_iterator i = words.begin(); i != words.end(); ++i) {
+        entry->append(i->rawContent(), i->length());
+        entry->append(" ",1);
+    }
 }
 
 static void
