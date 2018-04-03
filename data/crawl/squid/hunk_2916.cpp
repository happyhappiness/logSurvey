     StoreEntry *e;
 
     if (state->theSearch->isDone()) {
+        if (UsingSmp())
+            storeAppendPrintf(state->sentry, "} by kid%d\n\n", KidIdentifier);
         state->sentry->complete();
         state->sentry->unlock();
         cbdataFree(state);
