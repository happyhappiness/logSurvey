 }
 
 static void
-dump_wordlist(wordlist * list)
+dump_wordlist(StoreEntry *entry, const char *name, wordlist * list)
 {
-    printf("{");
     while (list != NULL) {
-	printf("%s ", list->key);
+	storeAppendPrintf(entry, "%s %s\n", name, list->key);
 	list = list->next;
     }
-    printf("}");
 }
 
 static void
