         return t;
     }
 }
+
+static void
+parse_logformat(logformat ** logformat_definitions)
+{
+    logformat *nlf;
+    char *name, *def;
+
+    if ((name = strtok(NULL, w_space)) == NULL)
+        self_destruct();
+
+    if ((def = strtok(NULL, "\r\n")) == NULL)
+        self_destruct();
+
+    debug(3, 1) ("Logformat for '%s' is '%s'\n", name, def);
+
+    nlf = (logformat *)xcalloc(1, sizeof(logformat));
+
+    nlf->name = xstrdup(name);
+
+    if (!accessLogParseLogFormat(&nlf->format, def))
+        self_destruct();
+
+    nlf->next = *logformat_definitions;
+
+    *logformat_definitions = nlf;
+}
+
+static void
+parse_access_log(customlog ** logs)
+{
+    const char *filename, *logdef_name;
+    customlog *cl;
+    logformat *lf;
+
+    cl = (customlog *)xcalloc(1, sizeof(*cl));
+
+    if ((filename = strtok(NULL, w_space)) == NULL)
+        self_destruct();
+
+    if (strcmp(filename, "none") == 0) {
+        cl->type = CLF_NONE;
+        goto done;
+    }
+
+    if ((logdef_name = strtok(NULL, w_space)) == NULL)
+        logdef_name = "auto";
+
+    debug(3, 9) ("Log definition name '%s' file '%s'\n", logdef_name, filename);
+
+    cl->filename = xstrdup(filename);
+
+    /* look for the definition pointer corresponding to this name */
+    lf = Config.Log.logformats;
+
+    while (lf != NULL) {
+        debug(3, 9) ("Comparing against '%s'\n", lf->name);
+
+        if (strcmp(lf->name, logdef_name) == 0)
+            break;
+
+        lf = lf->next;
+    }
+
+    if (lf != NULL) {
+        cl->type = CLF_CUSTOM;
+        cl->logFormat = lf;
+    } else if (strcmp(logdef_name, "auto") == 0) {
+        cl->type = CLF_AUTO;
+    } else if (strcmp(logdef_name, "squid") == 0) {
+        cl->type = CLF_SQUID;
+    } else if (strcmp(logdef_name, "common") == 0) {
+        cl->type = CLF_COMMON;
+    } else {
+        debug(3, 0) ("Log format '%s' is not defined\n", logdef_name);
+        self_destruct();
+    }
+
+done:
+    aclParseAclList(&cl->aclList);
+
+    while (*logs)
+        logs = &(*logs)->next;
+
+    *logs = cl;
+}
+
+static void
+dump_logformat(StoreEntry * entry, const char *name, logformat * definitions)
+{
+    accessLogDumpLogFormat(entry, name, definitions);
+}
+
+static void
+dump_access_log(StoreEntry * entry, const char *name, customlog * logs)
+{
+    customlog *log;
+
+    for (log = logs; log; log = log->next) {
+        storeAppendPrintf(entry, "%s ", name);
+
+        switch (log->type) {
+
+        case CLF_CUSTOM:
+            storeAppendPrintf(entry, "%s %s", log->filename, log->logFormat->name);
+            break;
+
+        case CLF_NONE:
+            storeAppendPrintf(entry, "none");
+            break;
+
+        case CLF_SQUID:
+            storeAppendPrintf(entry, "%s squid", log->filename);
+            break;
+
+        case CLF_COMMON:
+            storeAppendPrintf(entry, "%s squid", log->filename);
+            break;
+
+        case CLF_AUTO:
+
+            if (log->aclList)
+                storeAppendPrintf(entry, "%s auto", log->filename);
+            else
+                storeAppendPrintf(entry, "%s", log->filename);
+
+            break;
+
+        case CLF_UNKNOWN:
+            break;
+        }
+
+        if (log->aclList)
+            dump_acl_list(entry, log->aclList);
+
+        storeAppendPrintf(entry, "\n");
+    }
+}
+
+static void
+free_logformat(logformat ** definitions)
+{
+    while (*definitions) {
+        logformat *format = *definitions;
+        *definitions = format->next;
+        accessLogFreeLogFormat(&format->format);
+        xfree(format);
+    }
+}
+
+static void
+free_access_log(customlog ** definitions)
+{
+    while (*definitions) {
+        customlog *log = *definitions;
+        *definitions = log->next;
+
+        log->logFormat = NULL;
+        log->type = CLF_UNKNOWN;
+
+        if (log->aclList)
+            aclDestroyAclList(&log->aclList);
+
+        safe_free(log->filename);
+
+        xfree(log);
+    }
+}
