         }
 
         /* Send it off to the helper */
-        memBufDefInit(&buf);
+        buf.init();
 
-        memBufPrintf(&buf, "%s\n", key);
+        buf.Printf("%s\n", key);
 
         helperSubmit(def->theHelper, buf.buf, externalAclHandleReply, state);
 
         dlinkAdd(state, &state->list, &def->queue);
 
-        memBufClean(&buf);
+        buf.clean();
     }
 
     if (graceful) {
