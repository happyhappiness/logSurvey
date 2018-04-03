 
     hdr_out->putStr(HDR_X_FORWARDED_FOR, strFwd.buf());
 
+#endif
     strFwd.clean();
 
     /* append Host if not there already */