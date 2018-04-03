         if (const char *value = (*i)->match(r, reply)) {
             buf.Printf("%s: %s\r\n", (*i)->key.termedBuf(), value);
             Adaptation::History::Pointer ah = request->adaptHistory(false);
-            if (ah != NULL && !ah->metaHeaders.hasByNameListMember((*i)->key.termedBuf(), value, ','))
-                ah->metaHeaders.addEntry(new HttpHeaderEntry(HDR_OTHER, (*i)->key.termedBuf(), value));
+            if (ah != NULL) {
+                if (ah->metaHeaders == NULL)
+                    ah->metaHeaders = new NotePairs;
+                if (!ah->metaHeaders->hasPair((*i)->key.termedBuf(), value))
+                    ah->metaHeaders->add((*i)->key.termedBuf(), value);
+            }
         }
     }
 
