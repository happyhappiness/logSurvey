         if (squid_curtime - first_warn > 3 * 60)
             fatal("ssl_crtvd queue being overloaded for long time");
         debugs(83, DBG_IMPORTANT, "WARNING: ssl_crtvd queue overload, rejecting");
-        const char *errMsg = "BH error 45 Temporary network problem, please retry later";
-        HelperReply failReply(errMsg,strlen(errMsg));
+        HelperReply failReply;
+        failReply.result = HelperReply::BrokenHelper;
+        failReply.notes.add("message", "error 45 Temporary network problem, please retry later");
         callback(data, failReply);
         return;
     }
