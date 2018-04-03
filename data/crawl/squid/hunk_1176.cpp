 
 // more adapted response body is available
 void
-ServerStateData::handleMoreAdaptedBodyAvailable()
+Client::handleMoreAdaptedBodyAvailable()
 {
     if (abortOnBadEntry("entry refuses adapted body"))
         return;
