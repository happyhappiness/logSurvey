 // called after parsing all headers or when bypassing an exception
 void Adaptation::Icap::ModXact::startSending()
 {
+    disableRepeats("sent headers");
     disableBypass("sent headers");
     sendAnswer(adapted.header);
 
