     icapReply = new HttpReply;
     icapReply->protoPrefix = "ICAP/"; // TODO: make an IcapReply class?
 
-    // XXX: make sure stop() cleans all buffers
+    debugs(93,7, "ICAPModXact initialized." << status());
 }
 
-// HTTP side starts sending virgin data
-void ICAPModXact::noteSourceStart(MsgPipe *p)
+// initiator wants us to start
+void ICAPModXact::start()
 {
-    ICAPXaction_Enter(noteSourceStart);
+    ICAPXaction_Enter(start);
 
-    // make sure TheBackupLimit is in-sync with the buffer size
-    Must(TheBackupLimit <= static_cast<size_t>(virgin->data->body->max_capacity));
+    ICAPXaction::start();
 
     estimateVirginBody(); // before virgin disappears!
 
