 
         if (Config.adminEmail)
             mail_warranty();
-        else
-            puts(dead_msg());
+	puts(dead_msg());
     }
 
+    if (shutting_down)
+	exit(1);
+
     abort();
 }
 
