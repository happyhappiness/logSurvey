         if (UsingSmp())
             storeAppendPrintf(state->sentry, "} by kid%d\n\n", KidIdentifier);
         state->sentry->complete();
-        state->sentry->unlock();
+        state->sentry->unlock("statObjects+isDone");
         cbdataFree(state);
         return;
     } else if (EBIT_TEST(state->sentry->flags, ENTRY_ABORTED)) {
-        state->sentry->unlock();
+        state->sentry->unlock("statObjects+aborted");
         cbdataFree(state);
         return;
     } else if (state->sentry->checkDeferRead(-1)) {
