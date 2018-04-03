     if (Config.errHtmlText == NULL)
 	Config.errHtmlText = xstrdup(null_string);
     storeConfigure();
-    if (Config2.Accel.on && !strcmp(Config.Accel.host, "virtual"))
+    if (Config2.Accel.on && !strcmp(Config.Accel.host, "virtual")) {
 	vhost_mode = 1;
+	if (Config.Accel.port == 0)
+	    vport_mode = 1;
+    }
     if (Config.Sockaddr.http == NULL)
 	fatal("No http_port specified!");
     snprintf(ThisCache, sizeof(ThisCache), "%s:%d (%s)",
