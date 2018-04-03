 #endif
     storeAppendPrintf(sentry, "\nsee also \"Memory utilization\" for detailed per type statistics\n");
 }
+
+#if CBDATA_DEBUG
+
+template <class T>
+T& for_each(Stack const &collection, T& visitor)
+{
+    for (int index = 0; index < collection.count; ++index)
+	visitor(*(typename T::argument_type const *)collection.items[index]);
+    return visitor;
+};
+
+struct CBDataCallDumper : public unary_function<CBDataCall, void>
+{
+    CBDataCallDumper (StoreEntry *anEntry):where(anEntry){}
+    void operator()(CBDataCall const &x) {
+	storeAppendPrintf(where, "%s\t%s\t%d\n", x.label, x.file, x.line);
+    }
+    StoreEntry *where;
+};
+
+struct CBDataHistoryDumper : public CBDataDumper
+{
+    CBDataHistoryDumper(StoreEntry *anEntry):CBDataDumper(anEntry),where(anEntry), callDumper(anEntry){}
+    void operator()(_cbdata const &x) {
+	CBDataDumper::operator()(x);
+	storeAppendPrintf(where, "\n");
+	storeAppendPrintf(where, "Action\tFile\tLine\n");
+	for_each (*x.calls,callDumper);
+	storeAppendPrintf(where, "\n");
+    }
+    StoreEntry *where;
+    CBDataCallDumper callDumper;
+};
+
+void
+cbdataDumpHistory(StoreEntry *sentry)
+{
+    storeAppendPrintf(sentry, "%d cbdata entries\n", cbdataCount);
+    storeAppendPrintf(sentry, "Pointer\tType\tLocks\tAllocated by\n");
+    CBDataHistoryDumper dumper(sentry);
+    for_each (cbdataEntries, dumper);
+}
+#endif