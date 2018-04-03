 
     httpHeaderAddContRange(&hdr, *spec, rep->content_length);
 
-    packerToMemInit(&p, mb);
-
-    hdr.packInto(&p);
-
-    packerClean(&p);
-
+    hdr.packInto(mb);
     hdr.clean();
 
     /* append <crlf> (we packed a header, not a reply) */
-    mb->Printf("\r\n");
+    mb->append("\r\n", 2);
 }
 
 /**
