     assert (spec->length >= 0);
 
     if (!known_spec(spec->offset) || !known_spec(spec->length))
-        p->Printf("*");
+        p->append("*", 1);
     else
-        p->Printf("bytes %" PRId64 "-%" PRId64,
-                     spec->offset, spec->offset + spec->length - 1);
+        p->appendf("bytes %" PRId64 "-%" PRId64, spec->offset, spec->offset + spec->length - 1);
 }
 
 /*
