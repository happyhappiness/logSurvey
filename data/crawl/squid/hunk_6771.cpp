 	reply->last_modified = ftpState->mdtm;
     }
     storeAppendPrintf(e, "\r\n");
+#else
+    httpReplyReset(reply);
+    /* set standard stuff */
+    httpReplySetHeaders(reply, 1.0, HTTP_OK, "Gatewaying",
+	mime_type, ftpState->size, ftpState->mdtm, -2);
+    /* additional info */
+    if (mime_enc)
+	httpHeaderSetStr(&reply->hdr, HDR_CONTENT_ENCODING, mime_enc);
+    httpReplySwapOut(reply, e);
+#endif
     storeBufferFlush(e);
     reply->hdr_sz = e->mem_obj->inmem_hi;
     storeTimestampsSet(e);
