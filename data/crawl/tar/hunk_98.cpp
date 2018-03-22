       ERROR ((0, 0, _("Extended header length is out of allowed range")));
       return false;
     }
-  
+
   if (len_max < len)
     {
       int len_len = len_lim - p;
