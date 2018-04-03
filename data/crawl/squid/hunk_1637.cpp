 MemObject::stat(MemBuf * mb) const
 {
     mb->Printf("\t%s %s\n",
-               RequestMethodStr(method), log_url);
+               RequestMethodStr(method), logUri());
     if (vary_headers)
         mb->Printf("\tvary_headers: %s\n", vary_headers);
     mb->Printf("\tinmem_lo: %" PRId64 "\n", inmem_lo);
