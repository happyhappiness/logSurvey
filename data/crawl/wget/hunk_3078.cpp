       logprintf (LOG_NOTQUIET, "%s: %s\n", file, strerror (errno));
       return NULL;
     }
-  DEBUGP (("Loaded %s (size %ld).\n", file, fm->length));
+  DEBUGP (("Loaded %s (size %s).\n", file, number_to_static_string (fm->length)));
 
   ctx.text = fm->content;
   ctx.head = ctx.tail = NULL;
