 char *elapsed_time();
 char *diskFileName();
 
-/* LOCALS */
-static char *open_bracket = "{\n";
-static char *close_bracket = "}\n";
-
 /* process utilization information */
 void stat_utilization_get(obj, sentry)
      cacheinfo *obj;
      StoreEntry *sentry;
 {
-    static char tempbuf[MAX_LINELEN];
     protocol_t proto_id;
     proto_stat *p = &obj->proto_stat_data[PROTO_MAX];
     proto_stat *q = NULL;
     int secs = 0;
 
     secs = (int) (squid_curtime - squid_starttime);
 
-    storeAppend(sentry, open_bracket, (int) strlen(open_bracket));
+    storeAppendPrintf(sentry, "{\n");
 
     p->object_count = 0;
     p->kb.max = 0;
