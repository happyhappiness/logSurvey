 }
 
 // unexpected connection close while talking to the ICAP service
-void ICAPXaction::noteCommClosed(const CommCloseCbParams &io)
+void Adaptation::Icap::Xaction::noteCommClosed(const CommCloseCbParams &io)
 {
     closer = NULL;
     handleCommClosed();
 }
 
-void ICAPXaction::handleCommClosed()
+void Adaptation::Icap::Xaction::handleCommClosed()
 {
     mustStop("ICAP service connection externally closed");
 }
 
-void ICAPXaction::callEnd()
+void Adaptation::Icap::Xaction::callEnd()
 {
     if (doneWithIo()) {
         debugs(93, 5, HERE << typeName << " done with I/O" << status());
