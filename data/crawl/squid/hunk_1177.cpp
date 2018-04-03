 
 // the entire adapted response body was produced, successfully
 void
-ServerStateData::handleAdaptedBodyProductionEnded()
+Client::handleAdaptedBodyProductionEnded()
 {
     if (abortOnBadEntry("entry went bad while waiting for adapted body eof"))
         return;
