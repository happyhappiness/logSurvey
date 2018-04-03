 }
 
 static void
-dump_address(StoreEntry * entry, const char *name, IPAddress &addr)
+dump_address(StoreEntry * entry, const char *name, IpAddress &addr)
 {
     char buf[MAX_IPSTRLEN];
     storeAppendPrintf(entry, "%s %s\n", name, addr.NtoA(buf,MAX_IPSTRLEN) );
 }
 
 static void
-parse_address(IPAddress *addr)
+parse_address(IpAddress *addr)
 {
     char *token = strtok(NULL, w_space);
 
