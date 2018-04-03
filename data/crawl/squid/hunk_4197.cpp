     return rep->raw();
 }
 
-bool
-Ecap::XactionRep::doneAll() const
+void
+Ecap::XactionRep::terminateMaster()
 {
     if (theMaster) {
-        if (!doneWithAdapted() || sendingVirgin())
-            return false;
-	}   
-
-    return Adaptation::Initiate::doneAll();
-}
-
-bool
-Ecap::XactionRep::doneWithAdapted() const
-{
-    if (!theAnswerRep)
-        return false;
-
-    // we are not done if we are producing
-    MessageRep *answer = dynamic_cast<MessageRep*>(theAnswerRep.get());
-	Must(answer);
-    const BodyPipePointer &ap = answer->raw().body_pipe;
-    return !ap || !ap->stillProducing(this);
+        AdapterXaction x = theMaster;
+        theMaster.reset();
+        x->stop();
+	}
 }
 
-// are we still sending virgin body to theMaster?
 bool
-Ecap::XactionRep::sendingVirgin() const
+Ecap::XactionRep::doneAll() const
 {
-    // we are sending if we are consuming
-    const BodyPipePointer &vp = theVirginRep.raw().body_pipe;
-    return vp != NULL && vp->stillConsuming(this);
+    return proxyingVb >= opComplete && proxyingAb >= opComplete &&
+        Adaptation::Initiate::doneAll();
 }
 
-// stops sending virgin to theMaster and enables auto-consumption
+// stops receiving virgin and enables auto-consumption
 void
 Ecap::XactionRep::dropVirgin(const char *reason)
 {
-    debugs(93,4, HERE << "because " << reason);
+    debugs(93,4, HERE << "because " << reason << "; status:" << status());
+    Must(proxyingVb = opOn);
 
     BodyPipePointer &p = theVirginRep.raw().body_pipe;
     Must(p != NULL);
     Must(p->stillConsuming(this));
     stopConsumingFrom(p);
     p->enableAutoConsumption();
-    if (doneWithAdapted())
-        theMaster.reset();
+    proxyingVb = opComplete;
+    canAccessVb = false;
+
+    // called from adapter handler so does not inform adapter
 }
 
 void 
 Ecap::XactionRep::useVirgin()
 {
     debugs(93,3, HERE << status());
+    Must(proxyingAb == opUndecided);
+    proxyingAb = opNever;
 
-    // XXX: check state everywhere
-    Must(!theAnswerRep);
-    theMaster.reset();
-
-	HttpMsg *answer = theVirginRep.raw().header->clone();
-	Must(!theVirginRep.raw().body_pipe == !answer->body_pipe); // check clone()
-
-	if (answer->body_pipe != NULL) {
+    BodyPipePointer &vbody_pipe = theVirginRep.raw().body_pipe;
+    if (proxyingVb == opOn) {
+        Must(vbody_pipe->stillConsuming(this));
         // if libecap consumed, we cannot shortcircuit
-        Must(!answer->body_pipe->consumedSize());
-        Must(answer->body_pipe->stillConsuming(this));
-		stopConsumingFrom(answer->body_pipe);
-    }
-
-	sendAnswer(answer);
+        Must(!vbody_pipe->consumedSize());
+        stopConsumingFrom(vbody_pipe);
+        canAccessVb = false;
+        proxyingVb = opComplete;
+    } else
+    if (proxyingVb == opUndecided)
+        proxyingVb = opNever;
+
+	HttpMsg *clone = theVirginRep.raw().header->clone();
+    // check that clone() copies the pipe so that we do not have to
+	Must(!theVirginRep.raw().header->body_pipe == !clone->body_pipe);
+    sendAnswer(clone);
     Must(done());
 }
 
 void 
 Ecap::XactionRep::useAdapted(const libecap::shared_ptr<libecap::Message> &m)
 {
     debugs(93,3, HERE << status());
+    Must(m);
     theAnswerRep = m;
-	MessageRep *rep = dynamic_cast<MessageRep*>(theAnswerRep.get());
-	Must(rep);
-	HttpMsg *answer = rep->raw().header;
-    if (!theAnswerRep->body()) {
-        if (!sendingVirgin())
-            theMaster.reset();
-        sendAnswer(answer);
-	} else {
-		Must(!answer->body_pipe); // only host can set body pipes
-		rep->tieBody(this);
+    Must(proxyingAb == opUndecided);
+
+	HttpMsg *msg = answer().header;
+    if (!theAnswerRep->body()) { // final, bodyless answer
+        proxyingAb = opNever;
+        sendAnswer(msg);
+	} else { // got answer headers but need to handle body
+        proxyingAb = opOn;
+		Must(!msg->body_pipe); // only host can set body pipes
+        MessageRep *rep = dynamic_cast<MessageRep*>(theAnswerRep.get());
+		Must(rep);
+		rep->tieBody(this); // sets us as a producer
+		Must(msg->body_pipe != NULL); // check tieBody
+
+        sendAnswer(msg);
+
         debugs(93,4, HERE << "adapter will produce body" << status());
         theMaster->abMake(); // libecap will produce
-        sendAnswer(answer);
     }
 }
 
 void
 Ecap::XactionRep::vbIgnore()
 {
+    Must(proxyingVb == opUndecided);
     // if adapter does not need vb, we do not need to send it
-    if (sendingVirgin())
-        dropVirgin("vbIgnore");
+    dropVirgin("vbIgnore");
+    Must(proxyingVb == opNever);
 }
 
 void
 Ecap::XactionRep::vbMake()
 {
-    Must(sendingVirgin());
-    theMaster->noteVbContentAvailable(); // XXX: async
+    Must(proxyingVb == opUndecided);
+    BodyPipePointer &p = theVirginRep.raw().body_pipe;
+    Must(p != NULL);
+    Must(p->setConsumerIfNotLate(this)); // to make vb, we must receive vb
+    proxyingVb = opOn;
 }
 
 void
 Ecap::XactionRep::vbStopMaking()
 {
-    // if adapter does not need vb, we do not need to send it
-    if (sendingVirgin())
-        dropVirgin("vbIgnore");
+    // if adapter does not need vb, we do not need to receive it
+    if (proxyingVb == opOn)
+        dropVirgin("vbStopMaking");
+    Must(proxyingVb == opComplete);
 }
 
 void
 Ecap::XactionRep::vbMakeMore()
 {
-    Must(sendingVirgin() && !theVirginRep.raw().body_pipe->exhausted());
+    Must(proxyingVb == opOn); // cannot make more if done proxying
+    // we cannot guarantee more vb, but we can check that there is a chance
+    Must(!theVirginRep.raw().body_pipe->exhausted());
 }
 
 libecap::Area
 Ecap::XactionRep::vbContent(libecap::off_type o, libecap::size_type s)
 {
+    Must(canAccessVb);
+    // We may not be proxyingVb yet. It should be OK, but see vbContentShift().
+
     const BodyPipePointer &p = theVirginRep.raw().body_pipe;
-    const size_t haveSize = static_cast<size_t>(p->buf().contentSize()); // TODO: make MemBuf use size_t?
+    Must(p != NULL);
+
+    // TODO: make MemBuf use size_t?
+    const size_t haveSize = static_cast<size_t>(p->buf().contentSize());
 
     // convert to Squid types; XXX: check for overflow
     const uint64_t offset = static_cast<uint64_t>(o);
