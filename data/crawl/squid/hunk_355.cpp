         ErrorState *err = new ErrorState(ERR_WRITE_ERROR, Http::scBadGateway, fwd->request);
         err->xerrno = io.xerrno;
         fwd->fail(err);
-        serverConnection->close();
+        closeServer();
+        mustStop("HttpStateData::wroteLast");
         return;
     }
 
