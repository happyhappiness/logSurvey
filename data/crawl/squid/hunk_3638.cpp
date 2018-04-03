     mergeOfIcapHeaders.compact();
 }
 
-void Adaptation::Icap::History::start(const char *context) 
+void Adaptation::Icap::History::start(const char *context)
 {
     if (!concurrencyLevel++)
         currentStart = current_time;
 
     debugs(93,4, HERE << "start " << context << " level=" << concurrencyLevel
-        << " time=" << pastTime << ' ' << this);
+           << " time=" << pastTime << ' ' << this);
 }
 
-void Adaptation::Icap::History::stop(const char *context) 
+void Adaptation::Icap::History::stop(const char *context)
 {
     if (!concurrencyLevel) {
         debugs(93,1, HERE << "Internal error: poor history accounting " << this);
