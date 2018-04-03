 }
 
 void
-ServerStateData::resumeBodyStorage()
+Client::resumeBodyStorage()
 {
     if (abortOnBadEntry("store entry aborted while kick producer callback"))
         return;
