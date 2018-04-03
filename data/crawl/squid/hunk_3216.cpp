     requestData->error = 0;
     GetHHA1(requestData);
     if (requestData->error) {
-        printf("ERR No such user\n");
+        SEND_ERR("No such user");
         return;
     }
     printf("%s\n", requestData->HHA1);
