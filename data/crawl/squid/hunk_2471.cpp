         break;
 
     case 'I':
-        if (request && request->hier.host[0] != '\0') // if non-empty string
-            mb.Printf("%s", request->hier.host);
+        if (request && request->hier.tcpServer != NULL)
+            p = request->hier.tcpServer->remote.NtoA(ntoabuf,MAX_IPSTRLEN);
         else if (!building_deny_info_url)
             p = "[unknown]";
         break;