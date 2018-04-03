 struct CBDataCallDumper : public unary_function<CBDataCall, void> {
     CBDataCallDumper (StoreEntry *anEntry):where(anEntry) {}
 
-    void operator()(CBDataCall const &x) {
-        storeAppendPrintf(where, "%s\t%s\t%d\n", x.label, x.file, x.line);
+    void operator()(CBDataCall * const &x) {
+        storeAppendPrintf(where, "%s\t%s\t%d\n", x->label, x->file, x->line);
     }
 
     StoreEntry *where;
