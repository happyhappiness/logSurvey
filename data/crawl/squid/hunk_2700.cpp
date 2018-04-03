 
     if (canIgnore && srcIntact && adapted) {
         debugs(85,3, HERE << "responding with older adapted msg");
-        sendAnswer(theMsg);
+        sendAnswer(Answer::Forward(theMsg));
         mustStop("sent older adapted msg");
         return;
     }
