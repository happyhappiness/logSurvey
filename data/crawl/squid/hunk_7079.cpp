 
 
 static void
-dump_ushortlist(ushortlist * u)
+dump_ushortlist(StoreEntry *entry, const char *name, ushortlist * u)
 {
     while (u) {
-	printf("%d ", (int) u->i);
+	storeAppendPrintf(entry, "%s %d\n", name, (int) u->i);
 	u = u->next;
     }
 }
 
+static int
+check_null_ushortlist(ushortlist * u)
+{
+    return u == NULL;
+}
+
 static void
 parse_ushortlist(ushortlist ** P)
 {
