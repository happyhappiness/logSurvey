         }
 
         /* XXX this may end up having to be serverComplete() .. */
-        abortTransaction("zero control reply read");
+        abortAll("zero control reply read");
         return;
     }
 
