 	(int) (i->expires - squid_curtime),
 	i->addr_count);
     for (k = 0; k < (int) i->addr_count; k++)
-        xmemcpy(&addr.s_addr, i->entry.h_addr_list[k], sizeof(struct in_addr));
-        storeAppendPrintf(sentry, " %15s", inet_ntoa(addr));
+	xmemcpy(&addr.s_addr, i->entry.h_addr_list[k], sizeof(struct in_addr));
+    storeAppendPrintf(sentry, " %15s", inet_ntoa(addr));
     for (k = 0; k < (int) i->alias_count; k++)
 	storeAppendPrintf(sentry, " %s", i->entry.h_aliases[k]);
     if (i->entry.h_name && strncmp(i->name, i->entry.h_name, MAX_LINELEN))
