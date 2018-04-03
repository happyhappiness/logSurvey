 };
 
 void
-MemObject::stat (MemBuf * mb) const
+MemObject::stat(MemBuf * mb) const
 {
     mb->Printf("\t%s %s\n",
                RequestMethodStr(method), log_url);
+    if (vary_headers)
+        mb->Printf("\tvary_headers: %s\n", vary_headers);
     mb->Printf("\tinmem_lo: %"PRId64"\n", inmem_lo);
     mb->Printf("\tinmem_hi: %"PRId64"\n", data_hdr.endOffset());
     mb->Printf("\tswapout: %"PRId64" bytes queued\n",