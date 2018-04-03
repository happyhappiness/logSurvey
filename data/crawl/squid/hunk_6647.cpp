 	    istate = isError;
 	}
     }
-    /* printf("\n\n\n<pre>%s</pre>\n", req->headers ? req->headers : "no headers"); */
     close(s);
     return 0;
 }
