 
     // Do not use "227 =a,b,c,d,p1,p2" format or omit parens: some nf_ct_ftp
     // versions block responses that use those alternative syntax rules!
-    mb.Printf("227 Entering Passive Mode (%s,%i,%i).\n",
+    mb.Printf("227 Entering Passive Mode (%s,%i,%i).\r\n",
               addr,
               static_cast<int>(port / 256),
               static_cast<int>(port % 256));