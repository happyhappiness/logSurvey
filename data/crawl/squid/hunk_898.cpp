 HttpHdrRangeSpec::packInto(Packer * packer) const
 {
     if (!known_spec(offset))    /* suffix */
-        packerPrintf(packer, "-%" PRId64,  length);
+        packer->Printf("-%" PRId64,  length);
     else if (!known_spec(length))       /* trailer */
-        packerPrintf(packer, "%" PRId64 "-", offset);
+        packer->Printf("%" PRId64 "-", offset);
     else            /* range */
-        packerPrintf(packer, "%" PRId64 "-%" PRId64,
-                     offset, offset + length - 1);
+        packer->Printf("%" PRId64 "-%" PRId64, offset, offset + length - 1);
 }
 
 void
