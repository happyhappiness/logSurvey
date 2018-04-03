 
         RFCNB_errno = RFCNBE_NoSpace;
         RFCNB_saved_errno = errno;
-        return(RFCNBE_Bad);
+        return (RFCNBE_Bad);
 
     }
-
-    pkt -> next = Data;  /* Plug in the data portion */
+    pkt->next = Data;           /* Plug in the data portion */
 
     if ((ret_len = RFCNB_Get_Pkt(con_Handle, pkt, Length + RFCNB_Pkt_Hdr_Len)) < 0) {
 
 #ifdef RFCNB_DEBUG
         fprintf(stderr, "Bad packet return in RFCNB_Recv... \n");
 #endif
 
-        return(RFCNBE_Bad);
+        return (RFCNBE_Bad);
 
     }
-
     /* We should check that we go a message and not a keep alive */
 
-    pkt -> next = NULL;
+    pkt->next = NULL;
 
     RFCNB_Free_Pkt(pkt);
 
-    return(ret_len);
-
+    return (ret_len);
 }
 
 /* We just disconnect from the other end, as there is nothing in the RFCNB */
 /* protocol that specifies any exchange as far as I can see                */
-
-int RFCNB_Hangup(struct RFCNB_Con *con_Handle)
-
+int
+RFCNB_Hangup(struct RFCNB_Con *con_Handle)
 {
 
     if (con_Handle != NULL) {
-        RFCNB_Close(con_Handle -> fd);  /* Could this fail? */
+        RFCNB_Close(con_Handle->fd);    /* Could this fail? */
         free(con_Handle);
     }
-
     return 0;
-
-
 }
 
 /* Set TCP_NODELAY on the socket                                          */
-
-int RFCNB_Set_Sock_NoDelay(struct RFCNB_Con *con_Handle, BOOL yn)
-
+int
+RFCNB_Set_Sock_NoDelay(struct RFCNB_Con *con_Handle, BOOL yn)
 {
 
-    return(setsockopt(con_Handle -> fd, IPPROTO_TCP, TCP_NODELAY,
-                      (char *)&yn, sizeof(yn)));
-
+    return (setsockopt(con_Handle->fd, IPPROTO_TCP, TCP_NODELAY,
+                       (char *) &yn, sizeof(yn)));
 }
 
 #if NOT_IMPLEMENTED
-
 /* Listen for a connection on a port???, when                             */
 /* the connection comes in, we return with the connection                 */
-
-void *RFCNB_Listen()
-
+void *
+RFCNB_Listen()
 {
-
 }
+
 #endif
 
 /* Pick up the last error response as a string, hmmm, this routine should */
 /* have been different ...                                                */
-
-void RFCNB_Get_Error(char *buffer, int buf_len)
-
+void
+RFCNB_Get_Error(char *buffer, int buf_len)
 {
 
     if (RFCNB_saved_errno <= 0) {
-        snprintf(buffer, (buf_len-1) ,"%s", RFCNB_Error_Strings[RFCNB_errno]);
+        snprintf(buffer, (buf_len - 1), "%s", RFCNB_Error_Strings[RFCNB_errno]);
     } else {
-        snprintf(buffer, (buf_len-1), "%s\n\terrno:%s", RFCNB_Error_Strings[RFCNB_errno],
+        snprintf(buffer, (buf_len - 1), "%s\n\terrno:%s", RFCNB_Error_Strings[RFCNB_errno],
                  strerror(RFCNB_saved_errno));
     }
-
 }
 
 /* Pick up the last error response and returns as a code                 */
-
-int RFCNB_Get_Last_Error()
-
+int
+RFCNB_Get_Last_Error()
 {
-
-    return(RFCNB_errno);
-
+    return (RFCNB_errno);
 }
 
 /* Pick up saved errno as well */
-
-int RFCNB_Get_Last_Errno()
-
+int
+RFCNB_Get_Last_Errno()
 {
-
-    return(RFCNB_saved_errno);
-
+    return (RFCNB_saved_errno);
 }
 
 /* Pick up the last error response and return in string ...             */
-
-int RFCNB_Get_Error_Msg(int code, char *msg_buf, int len)
-
+int
+RFCNB_Get_Error_Msg(int code, char *msg_buf, int len)
 {
-
     return (strncpy(msg_buf, RFCNB_Error_Strings[abs(code)], len) != NULL);
-
 }
 
 /* Register a higher level protocol print routine */
-
-void RFCNB_Register_Print_Routine(void (*fn)())
-
+void
+RFCNB_Register_Print_Routine(RFCNB_Prot_Print_Routine * fn)
 {
-
     Prot_Print_Routine = fn;
-
 }
