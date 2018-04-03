         }
     }
 
+    if (Config.Accel.host) {
+        snprintf(buf, BUFSIZ, "http://%s:%d", Config.Accel.host, Config.Accel.port);
+        Config2.Accel.prefix = xstrdup(buf);
+        Config2.Accel.on = 1;
+    }
+
     if (Config.appendDomain)
         if (*Config.appendDomain != '.')
             fatal("append_domain must begin with a '.'");
