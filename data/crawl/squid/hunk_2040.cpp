         if (squid_curtime - first_warn > 3 * 60)
             fatal("SSL servers not responding for 3 minutes");
         debugs(34, DBG_IMPORTANT, HERE << "Queue overload, rejecting");
-        callback(data, (char *)"error 45 Temporary network problem, please retry later");
+        const char *errMsg = "BH error 45 Temporary network problem, please retry later"; // XXX: upgrade to message=""
+        callback(data, HelperReply(errMsg,strlen(errMsg)));
         return;
     }
 
