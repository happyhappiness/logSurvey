     }
 
   if (num_pattern_rules != rules)
-    fatal ("BUG: num_pattern_rules wrong!  %u != %u",
+    fatal (NILF, "BUG: num_pattern_rules wrong!  %u != %u",
 	   num_pattern_rules, rules);
 
   puts ("\n# Pattern-specific variable values");
