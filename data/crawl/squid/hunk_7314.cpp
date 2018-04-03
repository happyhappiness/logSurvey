 	    FqdncacheStats.hits++;
 	fqdncacheAddPending(f, fd, handler, handlerData);
 	fqdncache_call_pending(f);
-	return 0;
+	return;
     } else if (f->status == FQDN_PENDING || f->status == FQDN_DISPATCHED) {
 	debug(35, 4, "fqdncache_nbgethostbyaddr: PENDING for '%s'\n", name);
 	FqdncacheStats.pending_hits++;
 	fqdncacheAddPending(f, fd, handler, handlerData);
-	return 0;
+	if (squid_curtime - f->expires > 600) {
+	    debug(14, 0, "fqdncache_nbgethostbyname: '%s' PENDING for %d seconds, aborting\n", name, squid_curtime + Config.negativeDnsTtl - f->expires);
+	    fqdncacheChangeKey(f);
+	    fqdncache_call_pending(f);
+	}
+	return;
     } else {
 	fatal_dump("fqdncache_nbgethostbyaddr: BAD fqdncache_entry status");
     }
 
     /* for HIT, PENDING, DISPATCHED we've returned.  For MISS we continue */
 
-    if ((dnsData = dnsGetFirstAvailable()))
+    if ((dnsData = dnsGetFirstAvailable())) {
 	fqdncache_dnsDispatch(dnsData, f);
-    else
+	return;
+    }
+    if (NDnsServersAlloc > 0) {
 	fqdncacheEnqueue(f);
-    return 0;
+	return;
+    }
+    fqdncache_gethostbyaddr(addr, FQDN_BLOCKING_LOOKUP);
+    fqdncache_call_pending(f);
 }
 
 static void
