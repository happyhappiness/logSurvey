                 snprintf (tbuf, sizeof(tbuf), "%s %s %s",
                           "113", ThisCache,
                           "This cache hit is still fresh and more than 1 day old");
-                hdr->putStr(HDR_WARNING, tbuf);
+                hdr->putStr(Http::HdrType::WARNING, tbuf);
             }
         }
     }
