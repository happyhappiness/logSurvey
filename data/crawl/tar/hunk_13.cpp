 	      break;
 	      
 	    case 'T':
-	      compute_duration ();
-	      len += format_total_stats (fp, checkpoint_total_format, ',', 0);
+	      {
+		const char **fmt = checkpoint_total_format, *fmtbuf[3];
+		struct wordsplit ws;
+		compute_duration ();
+		
+		if (arg)
+		  {
+		    ws.ws_delim = ",";
+		    if (wordsplit (arg, &ws, WRDSF_NOVAR | WRDSF_NOCMD |
+				           WRDSF_QUOTE | WRDSF_DELIM))
+		      ERROR ((0, 0, _("cannot split string '%s': %s"),
+			      arg, wordsplit_strerror (&ws)));
+		    else
+		      {
+			int i;
+
+			for (i = 0; i < ws.ws_wordc; i++)
+			  fmtbuf[i] = ws.ws_wordv[i];
+			for (; i < 3; i++)
+			  fmtbuf[i] = NULL;
+			fmt = fmtbuf;
+		      }
+		  }
+		len += format_total_stats (fp, fmt, ',', 0);
+		if (arg)
+		  wordsplit_free (&ws);
+	      }
 	      break;
 
 	    case 't':
