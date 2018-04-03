     StoreEntry *sentry = w;
     rtentry *e = (rtentry *) rn;
     intlist *q;
-    as_info *as_info;
+    as_info *asinfo;
     struct in_addr addr;
     struct in_addr mask;
     assert(e);
+    assert(e->e_info);
     (void) get_m_int(addr.s_addr, e->e_addr);
     (void) get_m_int(mask.s_addr, e->e_mask);
     storeAppendPrintf(sentry, "%15s/%d\t",
 	inet_ntoa(addr), mask_len(ntohl(mask.s_addr)));
-    assert(as_info = e->e_info);
-    assert(as_info->as_number);
-    for (q = as_info->as_number; q; q = q->next)
+    asinfo = e->e_info;
+    assert(asinfo->as_number);
+    for (q = asinfo->as_number; q; q = q->next)
 	storeAppendPrintf(sentry, " %d", q->i);
     storeAppendPrintf(sentry, "\n");
     return 0;
