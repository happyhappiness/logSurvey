 {
     intlist *prev = NULL;
     intlist *data = e_info->as_number;
+
     while (data) {
-	prev = data;
-	data = data->next;
-	xfree(prev);
+        prev = data;
+        data = data->next;
+        xfree(prev);
     }
+
     xfree(data);
 }
 
 static int
 mask_len(u_long mask)
 {
     int len = 32;
+
     if (mask == 0)
-	return 0;
+        return 0;
+
     while ((mask & 1) == 0) {
-	len--;
-	mask >>= 1;
+        len--;
+        mask >>= 1;
     }
+
     return len;
 }
 
 static int
+
 printRadixNode(struct squid_radix_node *rn, void *_sentry)
 {
     StoreEntry *sentry = (StoreEntry *)_sentry;
     rtentry_t *e = (rtentry_t *) rn;
     intlist *q;
     as_info *asinfo;
+
     struct in_addr addr;
+
     struct in_addr mask;
     assert(e);
     assert(e->e_info);
     (void) get_m_int(addr.s_addr, e->e_addr);
     (void) get_m_int(mask.s_addr, e->e_mask);
     storeAppendPrintf(sentry, "%15s/%d\t",
-	inet_ntoa(addr), mask_len(ntohl(mask.s_addr)));
+                      inet_ntoa(addr), mask_len(ntohl(mask.s_addr)));
     asinfo = e->e_info;
     assert(asinfo->as_number);
+
     for (q = asinfo->as_number; q; q = q->next)
-	storeAppendPrintf(sentry, " %d", q->i);
+        storeAppendPrintf(sentry, " %d", q->i);
+
     storeAppendPrintf(sentry, "\n");
+
     return 0;
 }
