         connState->ftp.dataConn = params.conn;
         connState->ftp.uploadAvailSize = 0;
         debugs(33, 7, "ready for data");
+        if (connState->ftp.onDataAcceptCall != NULL) {
+            AsyncCall::Pointer call = connState->ftp.onDataAcceptCall;
+            connState->ftp.onDataAcceptCall = NULL;
+            // If we got an upload request, start reading data from the client.
+            if (connState->ftp.state == ConnStateData::FTP_HANDLE_UPLOAD_REQUEST)
+                connState->readSomeFtpData();
+            else
+                Must(connState->ftp.state == ConnStateData::FTP_HANDLE_DATA_REQUEST);
+            MemBuf mb;
+            mb.init();
+            mb.Printf("150 Data connection opened.\r\n");
+            Comm::Write(connState->clientConnection, &mb, call);
+        }
     }
 }
 
