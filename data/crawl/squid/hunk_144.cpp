         }
 
         if (!parsedOk) {
-            if (hp->parseStatusCode == Http::scRequestHeaderFieldsTooLarge || hp->parseStatusCode == Http::scUriTooLong)
-                return csd->abortRequestParsing("error:request-too-large");
-
-            return csd->abortRequestParsing("error:invalid-request");
+            const bool tooBig =
+                hp->parseStatusCode == Http::scRequestHeaderFieldsTooLarge ||
+                hp->parseStatusCode == Http::scUriTooLong;
+            auto result = csd->abortRequestParsing(
+                              tooBig ? "error:request-too-large" : "error:invalid-request");
+            // assume that remaining leftovers belong to this bad request
+            csd->consumeInput(csd->inBuf.length());
+            return result;
         }
     }
 