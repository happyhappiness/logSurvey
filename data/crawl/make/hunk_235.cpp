         if (i != -2)
           {
             if (i == -1)
-              fatal (fstart, _("invalid syntax in conditional"));
+              O (fatal, fstart, _("invalid syntax in conditional"));
 
             ignoring = i;
             continue;
