         if (++calls == 2)
             theLoop.stop();
     }
+
+    bool dispatch()
+    {
+        if (++calls == 2)
+            theLoop.stop();
+
+        return true;
+    }
 };
 
 void
