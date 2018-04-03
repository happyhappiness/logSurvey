         return;
 
     if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
-        abortTransaction("entry aborted during control reply read");
-        return;
+        if (abortOnData("entry aborted during control reply read"))
+            return;
     }
 
     assert(ctrl.offset < ctrl.size);
