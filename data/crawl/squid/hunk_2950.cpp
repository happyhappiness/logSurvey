     case RFCNB_SESSION_KEEP_ALIVE:
 
         fprintf(fd, "RFCNB SESSION KEEP ALIVE: Length = %i\n",
-                RFCNB_Pkt_Len(pkt->data));
+                RFCNB_Pkt_Len(pkt -> data));
         break;
 
     default:
