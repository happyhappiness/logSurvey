         break;
 
     default:
-        memBufPrintf(&mb, "%%%c", token);
+        mb.Printf("%%%c", token);
 
         do_quote = 0;
 
