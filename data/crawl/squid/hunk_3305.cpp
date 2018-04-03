     if (!doneSending() && state.sending != State::sendingUndecided)
         buf.Printf("S(%d)", state.sending);
 
+    if (state.readyForUob)
+        buf.append("6", 1);
+
     if (canStartBypass)
         buf.append("Y", 1);
 
