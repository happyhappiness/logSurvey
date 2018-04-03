     strcpy(dbg2, inet_ntoa(in_m));
     addr = ntohl(addr);
     mask = ntohl(mask);
-    debug(53, 3) ("asndbAddNet: called for %s/%s (%x/%x)\n", dbg1, dbg2, addr, mask);
+    debug(53, 3) ("asnAddNet: called for %s/%s (%x/%x)\n", dbg1, dbg2, addr, mask);
     memset(e, '\0', sizeof(rtentry));
     store_m_int(addr, e->e_addr);
     store_m_int(mask, e->e_mask);
     rn = rn_lookup(e->e_addr, e->e_mask, AS_tree_head);
     if (rn != 0) {
-	debug(53, 3) ("asndbAddNet: warning: Found a network with multiple AS numbers!\n");
-	info = ((rtentry *) rn)->e_info;
-	for (Tail = &(info->as_number); *Tail; Tail = &((*Tail)->next));
+	debug(53, 3) ("asnAddNet: warning: Found a network with multiple AS numbers!\n");
+	as_info = ((rtentry *) rn)->e_info;
+	for (Tail = &(as_info->as_number); *Tail; Tail = &((*Tail)->next));
 	q = xcalloc(1, sizeof(intlist));
 	q->i = as_number;
 	*(Tail) = q;
-	e->e_info = info;
+	e->e_info = as_info;
     } else {
 	q = xcalloc(1, sizeof(intlist));
 	q->i = as_number;
 	/* *(Tail) = q;         */
-	info = xmalloc(sizeof(as_info));
-	info->as_number = q;
+	as_info = xmalloc(sizeof(as_info));
+	as_info->as_number = q;
 	rn = rn_addroute(e->e_addr, e->e_mask, AS_tree_head, e->e_nodes);
 	rn = rn_match(e->e_addr, AS_tree_head);
-	if (rn == NULL)
-	    fatal_dump("cannot add entry...\n");
-	e->e_info = info;
-
+	assert(rn != NULL);
+	e->e_info = as_info;
     }
     if (rn == 0) {
 	xfree(e);
-	debug(53, 3) ("asndbAddNet: Could not add entry.\n");
+	debug(53, 3) ("asnAddNet: Could not add entry.\n");
 	return 0;
     }
-    e->e_info = info;
-    debug(53, 3) ("asndbAddNet: added successfully.\n");
+    e->e_info = as_info;
+    debug(53, 3) ("asnAddNet: added successfully.\n");
     return 1;
 }
 
