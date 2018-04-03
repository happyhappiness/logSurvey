 	    tp = find_next_token (&p2, &tlen);
 	    if (tp != 0)
 	      o = variable_buffer_output (o, tp, tlen);
-	    
+
 	    pp = find_next_token (&p3, &plen);
 	    if (pp != 0)
 	      o = variable_buffer_output (o, pp, plen);
-	    
+
 	    if (tp != 0 || pp != 0)
 	      {
 		o = variable_buffer_output (o, " ", 1);
