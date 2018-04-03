 
 // Entry-dependent callbacks use this check to quit if the entry went bad
 bool
-ServerStateData::abortOnBadEntry(const char *abortReason)
+Client::abortOnBadEntry(const char *abortReason)
 {
     if (entry->isAccepting())
         return false;
