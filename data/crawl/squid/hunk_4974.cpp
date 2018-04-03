         break;
 
     case 'e':
-        memBufPrintf(&mb, "%d", err->xerrno);
+        mb.Printf("%d", err->xerrno);
 
         break;
 
     case 'E':
 
         if (err->xerrno)
-            memBufPrintf(&mb, "(%d) %s", err->xerrno, strerror(err->xerrno));
+            mb.Printf("(%d) %s", err->xerrno, strerror(err->xerrno));
         else
-            memBufPrintf(&mb, "[No Error]");
+            mb.Printf("[No Error]");
 
         break;
 
