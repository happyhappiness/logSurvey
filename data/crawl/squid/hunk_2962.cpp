             free(tree);
         RFCNB_Free_Pkt(pkt);
         SMBlib_errno = -SMBlibE_RecvFailed;
-        return (NULL);
+        return(NULL);
 
     }
+
     /* Check out the response type ... */
 
-    if (CVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset) != SMBC_SUCCESS) {	/* Process error */
+    if (CVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset) != SMBC_SUCCESS) {  /* Process error */
 
 #ifdef DEBUG
         fprintf(stderr, "SMB_TCon failed with errorclass = %i, Error Code = %i\n",
