 
 /* initialize the radix tree structure */
 
-extern int max_keylen;		/* yuck.. this is in lib/radix.c */
+extern int squid_max_keylen;	/* yuck.. this is in lib/radix.c */
 
 CBDATA_TYPE(ASState);
 void
 asnInit(void)
 {
     static int inited = 0;
-    max_keylen = 40;
+    squid_max_keylen = 40;
     CBDATA_INIT_TYPE(ASState);
     if (0 == inited++)
-	rn_init();
-    rn_inithead((void **) &AS_tree_head, 8);
+	squid_rn_init();
+    squid_rn_inithead((void **) &AS_tree_head, 8);
     asnAclInitialize(Config.aclList);
     cachemgrRegister("asndb", "AS Number Database", asnStats, 0, 1);
 }
 
 void
 asnFreeMemory(void)
 {
-    rn_walktree(AS_tree_head, destroyRadixNode, AS_tree_head);
-    destroyRadixNode((struct radix_node *) 0, (void *) AS_tree_head);
+    squid_rn_walktree(AS_tree_head, destroyRadixNode, AS_tree_head);
+    destroyRadixNode((struct squid_radix_node *) 0, (void *) AS_tree_head);
 }
 
 static void
 asnStats(StoreEntry * sentry)
 {
     storeAppendPrintf(sentry, "Address    \tAS Numbers\n");
-    rn_walktree(AS_tree_head, printRadixNode, sentry);
+    squid_rn_walktree(AS_tree_head, printRadixNode, sentry);
 }
 
 /* PRIVATE */
