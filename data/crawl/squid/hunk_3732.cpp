                " bytes");
         virginBodySending.progress(size);
         virginConsume();
+        disableRepeats("echoed content");
         disableBypass("echoed content");
     }
 
