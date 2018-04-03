   else
     {
       if (var.value[0] != '\0')
-        error (&defstart, _("extraneous text after `define' directive"));
+        error (&defstart, _("extraneous text after 'define' directive"));
 
       /* Chop the string before the assignment token to get the name.  */
       var.name[var.length] = '\0';
