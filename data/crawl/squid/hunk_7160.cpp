 	debug(0, 0) ("'cache_effective_user' option in the config file.\n");
 	fatal("Don't run Squid as root, set 'cache_effective_user'!");
     }
+    assert(Config.Port.http);
     if (httpPortNumOverride != 1)
-	Config.Port.http[0] = (u_short) httpPortNumOverride;
+	Config.Port.http->i = (u_short) httpPortNumOverride;
     if (icpPortNumOverride != 1)
 	Config.Port.icp = (u_short) icpPortNumOverride;
 
