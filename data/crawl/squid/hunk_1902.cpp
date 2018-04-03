         if (first_warn == 0)
             first_warn = squid_curtime;
         if (squid_curtime - first_warn > 3 * 60)
-            fatal("SSL servers not responding for 3 minutes");
-        debugs(83, 1, HERE << "Queue overload, rejecting");
+            fatal("ssl_crtvd queue being overloaded for long time");
+        debugs(83, DBG_IMPORTANT, "WARNING: ssl_crtvd queue overload, rejecting");
         const char *errMsg = "BH error 45 Temporary network problem, please retry later";
         HelperReply failReply(errMsg,strlen(errMsg));
         callback(data, failReply);
