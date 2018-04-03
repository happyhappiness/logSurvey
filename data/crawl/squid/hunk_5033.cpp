 }
 
 static void
-OutputHHA1(RequestData *requestData)
+OutputHHA1(RequestData * requestData)
 {
     requestData->error = 0;
     GetHHA1(requestData);
-    if (requestData->error) {    
+    if (requestData->error) {
 	printf("ERR No such user\n");
 	return;
     }
