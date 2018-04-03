             }
 
             RFCNB_saved_errno = errno;
-            return(RFCNBE_Bad);
+            return (RFCNBE_Bad);
 
         }
-
 #ifdef RFCNB_DEBUG
         fprintf(stderr, "Frag_Len = %i, this_time = %i, this_len = %i, more = %i\n", frag_len,
                 this_time, this_len, more);
 #endif
 
-        read_len = read_len + this_time;  /* How much have we read ... */
+        read_len = read_len + this_time;        /* How much have we read ... */
 
         /* Now set up the next part */
 
-        if (pkt_frag -> next == NULL) break;       /* That's it here */
+        if (pkt_frag->next == NULL)
+            break;              /* That's it here */
 
-        pkt_frag = pkt_frag -> next;
-        this_len = pkt_frag -> len;
+        pkt_frag = pkt_frag->next;
+        this_len = pkt_frag->len;
         offset = 0;
 
         more = more - this_time;
 
     }
 
 #ifdef RFCNB_DEBUG
-    fprintf(stderr,"Pkt Len = %i, read_len = %i\n", pkt_len, read_len);
+    fprintf(stderr, "Pkt Len = %i, read_len = %i\n", pkt_len, read_len);
     RFCNB_Print_Pkt(stderr, "rcvd", pkt, read_len + sizeof(hdr));
 #endif
 
-    if (read_len < (pkt_len + sizeof(hdr))) {  /* Discard the rest */
+    if (read_len < (pkt_len + sizeof(hdr))) {   /* Discard the rest */
 
-        return(RFCNB_Discard_Rest(con, (pkt_len + sizeof(hdr)) - read_len));
+        return (RFCNB_Discard_Rest(con, (pkt_len + sizeof(hdr)) - read_len));
 
     }
-
     if (RFCNB_Timeout > 0)
-        alarm(0);                /* Reset that sucker */
+        alarm(0);               /* Reset that sucker */
 
-    return(read_len + sizeof(RFCNB_Hdr));
+    return (read_len + sizeof(RFCNB_Hdr));
 }
