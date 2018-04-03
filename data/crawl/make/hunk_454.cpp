           if (implicit_percent == 0)
             fatal (flocp, _("mixed implicit and normal rules"));
 
-	  targets[c] = name;
-	  target_pats[c] = implicit_percent;
+          targets[c] = name;
+          target_pats[c] = implicit_percent;
           ++c;
 
           nextf = filenames->next;
