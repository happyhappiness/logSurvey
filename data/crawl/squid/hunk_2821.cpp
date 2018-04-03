 {
     disableRepeats("sent headers");
     disableBypass("sent headers", true);
-    sendAnswer(adapted.header);
+    sendAnswer(Answer::Forward(adapted.header));
 
     if (state.sending == State::sendingVirgin)
         echoMore();
