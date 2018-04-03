         break;
 
     case 't':
-        memBufPrintf(&mb, "%s", mkhttpdlogtime(&squid_curtime));
+        mb.Printf("%s", mkhttpdlogtime(&squid_curtime));
         break;
 
     case 'T':
-        memBufPrintf(&mb, "%s", mkrfc1123(squid_curtime));
+        mb.Printf("%s", mkrfc1123(squid_curtime));
         break;
 
     case 'U':
