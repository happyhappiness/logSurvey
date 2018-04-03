     RequestData requestData;
     ParseBuffer(buf, &requestData);
     if (!requestData.parsed) {
-        printf("ERR\n");
+        SEND_ERR("");
         return;
     }
     OutputHHA1(&requestData);
