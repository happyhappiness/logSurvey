 }
 
 void
-SqStringRegistry::registerWithCacheManager(CacheManager & manager)
+StringRegistry::registerWithCacheManager(CacheManager & manager)
 {
     manager.registerAction("strings",
                            "Strings in use in squid", Stat, 0, 1);
 }
 
 void
-SqStringRegistry::add(SqString const *entry)
+
+StringRegistry::add
+    (String const *entry)
 {
     entries.insert(entry, ptrcmp);
 }
 
 void
-SqStringRegistry::remove(SqString const *entry)
+
+StringRegistry::remove
+    (String const *entry)
 {
     entries.remove(entry, ptrcmp);
 }
 
-SqStringRegistry SqStringRegistry::Instance_;
+StringRegistry StringRegistry::Instance_;
 
 extern size_t memStringCount();
 
 void
-SqStringRegistry::Stat(StoreEntry *entry)
+StringRegistry::Stat(StoreEntry *entry)
 {
     storeAppendPrintf(entry, "%lu entries, %lu reported from MemPool\n", (unsigned long) Instance().entries.elements, (unsigned long) memStringCount());
     Instance().entries.head->walk(Stater, entry);
 }
 
 void
-SqStringRegistry::Stater(SqString const * const & nodedata, void *state)
+StringRegistry::Stater(String const * const & nodedata, void *state)
 {
     StoreEntry *entry = (StoreEntry *) state;
     nodedata->stat(entry);
 }
 
 #endif
 
+/* TODO: move onto String */
+int
+stringHasWhitespace(const char *s)
+{
+    return strpbrk(s, w_space) != NULL;
+}
+
+/* TODO: move onto String */
+int
+stringHasCntl(const char *s)
+{
+    unsigned char c;
+
+    while ((c = (unsigned char) *s++) != '\0') {
+        if (c <= 0x1f)
+            return 1;
+
+        if (c >= 0x7f && c <= 0x9f)
+            return 1;
+    }
+
+    return 0;
+}
+
 /*
  * Similar to strtok, but has some rudimentary knowledge
  * of quoting
