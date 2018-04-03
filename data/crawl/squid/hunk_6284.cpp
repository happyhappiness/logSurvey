     destroyRadixNode((struct radix_node *) 0, (void *) AS_tree_head);
 }
 
+static void
+asnStats(StoreEntry * sentry)
+{
+    storeAppendPrintf(sentry, "Address    \tAS Numbers\n");
+    rn_walktree(AS_tree_head, printRadixNode, sentry);
+}
+
 /* PRIVATE */
 
 
