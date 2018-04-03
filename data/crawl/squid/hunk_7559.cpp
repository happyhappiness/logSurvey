 /* LOCALS */
 char *open_bracket = "{\n";
 char *close_bracket = "}\n";
+
+static void dummyhandler _PARAMS((cacheinfo *, StoreEntry *));
+static void info_get _PARAMS((cacheinfo *, StoreEntry *));
+static void info_get_mallstat _PARAMS((int, int, StoreEntry *));
+static void logReadEndHandler _PARAMS((int, int, log_read_data_t *));
+static void log_clear _PARAMS((cacheinfo *, StoreEntry *));
+static void log_disable _PARAMS((cacheinfo *, StoreEntry *));
+static void log_enable _PARAMS((cacheinfo *, StoreEntry *));
+static void log_get_start _PARAMS((cacheinfo *, StoreEntry *));
+static void log_status_get _PARAMS((cacheinfo *, StoreEntry *));
+static void parameter_get _PARAMS((cacheinfo *, StoreEntry *));
+static void proto_count _PARAMS((cacheinfo *, protocol_t, log_type));
+static void proto_newobj _PARAMS((cacheinfo *, protocol_t, int, int));
+static void proto_purgeobj _PARAMS((cacheinfo *, protocol_t, int));
+static void proto_touchobj _PARAMS((cacheinfo *, protocol_t, int));
+static void server_list _PARAMS((cacheinfo *, StoreEntry *));
+static void squidReadEndHandler _PARAMS((int, int, squid_read_data_t *));
+static void squid_get_start _PARAMS((cacheinfo *, StoreEntry *));
 static void statFiledescriptors _PARAMS((StoreEntry *));
+static void stat_get _PARAMS((cacheinfo *, char *req, StoreEntry *));
+static void stat_io_get _PARAMS((StoreEntry *));
+static void stat_obj _PARAMS((cacheinfo *, StoreEntry *, int vm_or_not));
+static void stat_utilization_get _PARAMS((cacheinfo *, StoreEntry *, char *desc));
+static int cache_size_get _PARAMS((cacheinfo *));
+static int logReadHandler _PARAMS((int, char *, int, log_read_data_t *));
+static int squidReadHandler _PARAMS((int, char *, int, squid_read_data_t *));
+static int memoryAccounted _PARAMS((void));
+static int mallinfoTotal _PARAMS((void));
 
 /* process utilization information */
-void stat_utilization_get(obj, sentry)
+static void stat_utilization_get(obj, sentry, desc)
      cacheinfo *obj;
      StoreEntry *sentry;
+     char *desc;
 {
     protocol_t proto_id;
     proto_stat *p = &obj->proto_stat_data[PROTO_MAX];
     proto_stat *q = NULL;
     int secs = 0;
 
     secs = (int) (squid_curtime - squid_starttime);
-
-    storeAppendPrintf(sentry, open_bracket);
-
+    storeAppendPrintf(sentry, "{ %s\n", desc);	/* } */
     strcpy(p->protoname, "TOTAL");
     p->object_count = 0;
     p->kb.max = 0;
