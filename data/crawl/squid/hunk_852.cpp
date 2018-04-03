         break;
 
     default:
-        mb.Printf("%%%c", token);
+        mb.appendf("%%%c", token);
         do_quote = 0;
         break;
     }
