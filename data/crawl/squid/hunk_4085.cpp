     if (RFCNB_Send(Con_Handle->Trans_Connect, pkt, pkt_len) < 0) {
 
 #ifdef DEBUG
-	fprintf(stderr, "Error sending TCon request\n");
+        fprintf(stderr, "Error sending TCon request\n");
 #endif
 
-	if (Tree_Handle == NULL)
-	    free(tree);
-	RFCNB_Free_Pkt(pkt);
-	SMBlib_errno = -SMBlibE_SendFailed;
-	return (NULL);
+        if (Tree_Handle == NULL)
+            free(tree);
+        RFCNB_Free_Pkt(pkt);
+        SMBlib_errno = -SMBlibE_SendFailed;
+        return (NULL);
 
     }
     /* Now get the response ... */
 
     if (RFCNB_Recv(Con_Handle->Trans_Connect, pkt, pkt_len) < 0) {
 
 #ifdef DEBUG
-	fprintf(stderr, "Error receiving response to TCon\n");
+        fprintf(stderr, "Error receiving response to TCon\n");
 #endif
 
-	if (Tree_Handle == NULL)
-	    free(tree);
-	RFCNB_Free_Pkt(pkt);
-	SMBlib_errno = -SMBlibE_RecvFailed;
-	return (NULL);
+        if (Tree_Handle == NULL)
+            free(tree);
+        RFCNB_Free_Pkt(pkt);
+        SMBlib_errno = -SMBlibE_RecvFailed;
+        return (NULL);
 
     }
     /* Check out the response type ... */
 
     if (CVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset) != SMBC_SUCCESS) {	/* Process error */
 
 #ifdef DEBUG
-	fprintf(stderr, "SMB_TCon failed with errorclass = %i, Error Code = %i\n",
-	    CVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset),
-	    SVAL(SMB_Hdr(pkt), SMB_hdr_err_offset));
+        fprintf(stderr, "SMB_TCon failed with errorclass = %i, Error Code = %i\n",
+                CVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset),
+                SVAL(SMB_Hdr(pkt), SMB_hdr_err_offset));
 #endif
 
-	if (Tree_Handle == NULL)
-	    free(tree);
-	SMBlib_SMB_Error = IVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset);
-	RFCNB_Free_Pkt(pkt);
-	SMBlib_errno = SMBlibE_Remote;
-	return (NULL);
+        if (Tree_Handle == NULL)
+            free(tree);
+        SMBlib_SMB_Error = IVAL(SMB_Hdr(pkt), SMB_hdr_rcls_offset);
+        RFCNB_Free_Pkt(pkt);
+        SMBlib_errno = SMBlibE_Remote;
+        return (NULL);
 
     }
     tree->tid = SVAL(SMB_Hdr(pkt), SMB_tconr_tid_offset);
     tree->mbs = SVAL(SMB_Hdr(pkt), SMB_tconr_mbs_offset);
 
 #ifdef DEBUG
     fprintf(stderr, "TConn succeeded, with TID=%i, Max Xmit=%i\n",
-	tree->tid, tree->mbs);
+            tree->tid, tree->mbs);
 #endif
 
     /* Now link the Tree to the Server Structure ... */
 
     if (Con_Handle->first_tree == NULL) {
 
-	Con_Handle->first_tree = tree;
-	Con_Handle->last_tree = tree;
+        Con_Handle->first_tree = tree;
+        Con_Handle->last_tree = tree;
 
     } else {
 
-	Con_Handle->last_tree->next = tree;
-	tree->prev = Con_Handle->last_tree;
-	Con_Handle->last_tree = tree;
+        Con_Handle->last_tree->next = tree;
+        tree->prev = Con_Handle->last_tree;
+        Con_Handle->last_tree = tree;
 
     }
 
