     proto_stat *p = &obj->proto_stat_data[PROTO_MAX];
     proto_stat *q = NULL;
     int secs = 0;
-    secs = (int) (squid_curtime - squid_starttime);
+    secs = (int) (squid_curtime - squid_start.tv_sec);
     storeAppendPrintf(sentry, "{ %s\n", desc);	/* } */
     strcpy(p->protoname, "TOTAL");
     p->object_count = 0;
