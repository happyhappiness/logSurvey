 
     if (preview.enabled()) {
         if (!preview.done())
-            buf.Printf("P(%d)", preview.debt());
+            buf.Printf("P(%d)", (int) preview.debt());
     }
 
     if (virginSendClaim.active())
