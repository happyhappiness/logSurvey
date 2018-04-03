     HttpRequest *r = HttpRequest::CreateFromUrl(url_);
 
     if (NULL == r)
-        fatal("mimeLoadIcon: cannot parse internal URL");
+        fatalf("mimeLoadIcon: cannot parse internal URL: %s", url_);
 
     e->mem_obj->request = r;
     HTTPMSGLOCK(e->mem_obj->request);
 
     HttpReply *reply = new HttpReply;
 
-    reply->setHeaders(Http::scOkay, NULL, mimeGetContentType(icon_), sb.st_size, sb.st_mtime, -1);
+    if (status == Http::scNoContent)
+        reply->setHeaders(status, NULL, NULL, 0, -1, -1);
+    else
+        reply->setHeaders(status, NULL, mimeGetContentType(icon_), sb.st_size, sb.st_mtime, -1);
     reply->cache_control = new HttpHdrCc();
     reply->cache_control->maxAge(86400);
     reply->header.putCc(reply->cache_control);
     e->replaceHttpReply(reply);
 
-    /* read the file into the buffer and append it to store */
-    buf = (char *)memAllocate(MEM_4K_BUF);
-    while ((n = FD_READ_METHOD(fd, buf, 4096)) > 0)
-        e->append(buf, n);
+    if (status == Http::scOkay) {
+        /* read the file into the buffer and append it to store */
+        int n;
+        char *buf = (char *)memAllocate(MEM_4K_BUF);
+        while ((n = FD_READ_METHOD(fd, buf, sizeof(*buf))) > 0)
+            e->append(buf, n);
+
+        file_close(fd);
+        memFree(buf, MEM_4K_BUF);
+    }
 
-    file_close(fd);
     e->flush();
     e->complete();
     e->timestampsSet();
     e->unlock("MimeIcon::created");
-    memFree(buf, MEM_4K_BUF);
     debugs(25, 3, "Loaded icon " << url_);
 }
 