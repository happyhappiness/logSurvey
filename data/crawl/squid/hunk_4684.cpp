             buf.Printf("P(%d)", (int) preview.debt());
     }
 
-    if (virginSendClaim.active())
+    if (virginBodySending.active())
         buf.append("B", 1);
 
     if (!state.doneParsing() && state.parsing != State::psIcapHeader)
