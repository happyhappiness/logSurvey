 
     case GOPHER_BIN:
         /* Rightnow We have no idea what it is. */
-        gopher_mime_content(&mb, gopherState->request, def_gopher_bin);
+        mime_enc = mimeGetContentEncoding(gopherState->request);
+        mime_type = mimeGetContentType(gopherState->request);
+        if (!mime_type)
+            mime_type = def_gopher_bin;
         break;
 
     case GOPHER_FILE:
 
     default:
-        gopher_mime_content(&mb, gopherState->request, def_gopher_text);
+        mime_enc = mimeGetContentEncoding(gopherState->request);
+        mime_type = mimeGetContentType(gopherState->request);
+        if (!mime_type)
+            mime_type = def_gopher_text;
         break;
     }
 
-    mb.Printf("\r\n");
-    EBIT_CLR(gopherState->entry->flags, ENTRY_FWD_HDR_WAIT);
-    gopherState->entry->append(mb.buf, mb.size);
-    mb.clean();
+    assert(entry->isEmpty());
+    EBIT_CLR(entry->flags, ENTRY_FWD_HDR_WAIT);
+
+    HttpReply *reply = new HttpReply;
+    entry->buffer();
+    HttpVersion version(1, 0);
+    reply->setHeaders(version, HTTP_OK, "Gatewaying", mime_type, -1, -1, -2);
+    if (mime_enc)
+        reply->header.putStr(HDR_CONTENT_ENCODING, mime_enc);
+
+    entry->replaceHttpReply(reply);
 }
 
 /**
