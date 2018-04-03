     if ((Read_denyusers() == 1) || (Read_allowusers() == 1)) {
         while (1) {
             memset(wstr, '\0', sizeof(wstr));
-            fgets(wstr, 255, stdin);
+            if (fgets(wstr, 255, stdin) == NULL)
+                break;
             puts("ERR");
         }
+        return 1;
     }
+
     /*
      * Make Check_forchange() the handle for HUP signals.
      * Don't use alarms any more. I don't think it was very
