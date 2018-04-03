 void ICAPServiceRep::noteNewOptions(ICAPOptXact *x)
 {
     Must(x);
-    Must(waiting());
-
-    theState = stateDown; // default in case we fail to set new options
+    Must(waiting);
+    waiting = false;
 
     changeOptions(x->options);
     x->options = NULL;
     delete x;
 
-    if (theOptions && theOptions->valid())
-        theState = stateUp;
-
-    debugs(93,6, "ICAPService got new options and is now " <<
-           (up() ? "up" : "down"));
+    debugs(93,3, "ICAPService got new options and is now " << status());
 
     scheduleUpdate();
-
     scheduleNotification();
 }
 
 void ICAPServiceRep::startGettingOptions()
 {
+    Must(!waiting);
     debugs(93,6, "ICAPService will get new options " << status());
-    theState = stateWait;
+    waiting = true;
 
     ICAPOptXact *x = new ICAPOptXact;
     x->start(self, &ICAPServiceRep_noteNewOptions, this);
-    // TODO: timeout incase ICAPOptXact never calls us back?
+    // TODO: timeout in case ICAPOptXact never calls us back?
 }
 
 void ICAPServiceRep::scheduleUpdate()
 {
-    int delay = -1;
+    if (updateScheduled)
+        return; // already scheduled
+
+    // XXX: move hard-coded constants from here to TheICAPConfig
+
+    // conservative estimate of how long the OPTIONS transaction will take
+    const int expectedWait = 20; // seconds
+
+    time_t when = 0;
 
     if (theOptions && theOptions->valid()) {
         const time_t expire = theOptions->expire();
+        debugs(93,7, "ICAPService options expire on " << expire << " >= " << squid_curtime);
 
-        if (expire > squid_curtime)
-            delay = expire - squid_curtime;
+        if (expire < 0) // unknown expiration time
+            when = squid_curtime + 60*60;
         else
-            if (expire >= 0)
-                delay = 1; // delay for expired or 'expiring now' options
-            else
-                delay = 60*60; // default for options w/o known expiration time
+        if (expire < expectedWait) // invalid expiration time
+            when = squid_curtime + 60*60;
+        else
+            when = expire - expectedWait; // before the current options expire
     } else {
-        delay = 5*60; // delay for a down service
+        when = squid_curtime + 3*60; // delay for a down service
     }
 
-    if (delay <= 0) {
-        debugs(93,0, "internal error: ICAPServiceRep failed to compute options update schedule");
-        delay = 5*60; // delay for an internal error
-    }
+    debugs(93,7, "ICAPService options raw update on " << when << " or " << (when - squid_curtime));
+    if (when < squid_curtime)
+        when = squid_curtime;
+
+    const int minUpdateGap = 1*60; // seconds
+    if (when < theLastUpdate + minUpdateGap)
+        when = theLastUpdate + minUpdateGap;
 
-    // with zero delay, the state changes to stateWait before
-    // notifications are sent out to clients
-    assert(delay > 0);
+    // TODO: keep the time of the last update to prevet too-frequent updates
 
-    debugs(93,7, "ICAPService will update options in " << delay << " sec");
+    const int delay = when - squid_curtime;
+
+    debugs(93,5, "ICAPService will update options in " << delay << " sec");
 
     eventAdd("ICAPServiceRep::noteTimeToUpdate",
              &ICAPServiceRep_noteTimeToUpdate, this, delay, 0, true);
-
-    // XXX: prompt updates of valid options should not disable concurrent ICAP
-    // xactions. 'Wait' state should not mark the service 'down'! This will
-    // also remove 'delay == 0' as a special case above.
+    updateScheduled = true;
 }
 
+// returns a temporary string depicting service status, for debugging
 const char *ICAPServiceRep::status() const
 {
+    static MemBuf buf;
+
+    buf.reset();
+    buf.append("[", 1);
+
+    if (up())
+        buf.append("up", 2);
+    else
+        buf.append("down", 4);
+
     if (!self)
-        return "[invalidated]";
+        buf.append(",gone", 5);
 
-    switch (theState) {
+    if (waiting)
+        buf.append(",wait", 5);
 
-    case stateInit:
-        return "[init]";
+    if (notifying)
+        buf.append(",notif", 6);
 
-    case stateWait:
-        return "[wait]";
+    if (theSessionFailures > 0)
+        buf.Printf(",F%d", theSessionFailures);
 
-    case stateUp:
-        return "[up]";
+    if (isSuspended)
+        buf.append(",susp", 5);
 
-    case stateDown:
-        return "[down]";
-    }
+    buf.append("]", 1);
+    buf.terminate();
 
-    return "[unknown]";
+    return buf.content();
 }
