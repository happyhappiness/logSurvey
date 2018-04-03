             if (r->hier.host)
                 p = r->hier.host;
             else
-                p = r->host;
+                p = r->GetHost();
         } else
             p = "[unknown host]";
 
         break;
 
     case 'i':
-        mb.Printf("%s", inet_ntoa(err->src_addr));
+        mb.Printf("%s", err->src_addr.NtoA(ntoabuf,MAX_IPSTRLEN));
 
         break;
 
