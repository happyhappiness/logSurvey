         break;
 
     case 'i':
-        mb.Printf("%s", src_addr.toStr(ntoabuf,MAX_IPSTRLEN));
+        mb.appendf("%s", src_addr.toStr(ntoabuf,MAX_IPSTRLEN));
         break;
 
     case 'I':
