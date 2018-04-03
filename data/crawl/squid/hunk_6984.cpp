     int diff;
     int hdr_sz;
     int content_length;
-
-    if (e->mem_obj == NULL)
-	fatal_dump("storeEntryValidLength: NULL mem_obj");
-
+    assert(e->mem_obj != NULL);
     hdr_sz = e->mem_obj->reply->hdr_sz;
     content_length = e->mem_obj->reply->content_length;
 
