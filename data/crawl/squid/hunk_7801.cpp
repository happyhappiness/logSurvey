 
     storeAppendPrintf(sentry, "{\n");
 
+    strcpy(p->protoname, "TOTAL");
     p->object_count = 0;
     p->kb.max = 0;
     p->kb.min = 0;
