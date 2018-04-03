 
     storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) credentialsTTL);
     storeAppendPrintf(entry, "%s basic casesensitive %s\n", name, casesensitive ? "on" : "off");
-    storeAppendPrintf(entry, "%s basic utf8 %s\n", name, utf8 ? "on" : "off");
     return true;
 }
 
 Auth::Basic::Config::Config() :
     credentialsTTL( 2*60*60 ),
-    casesensitive(0),
-    utf8(0)
+    casesensitive(0)
 {
     static const SBuf defaultRealm("Squid proxy-caching web server");
     realm = defaultRealm;
