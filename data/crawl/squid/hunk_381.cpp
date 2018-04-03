     fwd->fail(err);
     fwd->dontRetry(true);
 
-    abortTransaction("timely adaptation block");
+    abortOnData("timely adaptation block");
 }
 
 void
