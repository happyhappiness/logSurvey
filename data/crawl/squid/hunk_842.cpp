         }
 #endif
         if (!mb.contentSize())
-            mb.Printf("[No Error Detail]");
+            mb.append("[No Error Detail]", 17);
         break;
 
     case 'e':
-        mb.Printf("%d", xerrno);
+        mb.appendf("%d", xerrno);
         break;
 
     case 'E':
         if (xerrno)
-            mb.Printf("(%d) %s", xerrno, strerror(xerrno));
+            mb.appendf("(%d) %s", xerrno, strerror(xerrno));
         else
-            mb.Printf("[No Error]");
+            mb.append("[No Error]", 10);
         break;
 
     case 'f':
