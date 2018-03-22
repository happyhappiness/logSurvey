 		  ERROR ((0, e, _("%s: Cannot remove"), quotearg_colon (p)));
 		}
 	    }
-	  free (p);
 	}
-
     }
+  free (p);
+  
   free (current_dir);
 }
 
