 }
 
 /// called when kid terminates, sets exiting status
-void Kid::stop(status_type theExitStatus)
+void
+Kid::stop(PidStatus const theExitStatus)
 {
     assert(running());
     assert(startTime != 0);
