 {
     MemBuf mb;
     mb.init();
-    mb.vPrintf(fmt, vargs);
+    mb.vappendf(fmt, vargs);
     hdr->putStr(id, mb.buf);
     mb.clean();
 }
