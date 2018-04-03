         break;
 
     case 'h':
-        memBufPrintf(&mb, "%s", getMyHostname());
+        mb.Printf("%s", getMyHostname());
 
         break;
 
