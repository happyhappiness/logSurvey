          * We have even better reasons though:
          * see http://wiki.squid-cache.org/KnowledgeBase/VaryNotCaching
          */
-        if(!Config.errorDirectory) {
+        if (!Config.errorDirectory) {
             /* We 'negotiated' this ONLY from the Accept-Language. */
             rep->header.delById(HDR_VARY);
             rep->header.putStr(HDR_VARY, "Accept-Language");
         }
 
         /* add the Content-Language header according to RFC section 14.12 */
-        if(err_language) {
+        if (err_language) {
             rep->header.putStr(HDR_CONTENT_LANGUAGE, err_language);
-        }
-        else
+        } else
 #endif /* USE_ERROR_LOCALES */
         {
             /* default templates are in English */
             /* language is known unless error_directory override used */
-            if(!Config.errorDirectory)
+            if (!Config.errorDirectory)
                 rep->header.putStr(HDR_CONTENT_LANGUAGE, "en");
         }
 
