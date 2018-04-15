 			ret = 0;
 			break;
 		}
+		else
+		{
+			fprintf (stderr, "Unable to load plugin %s.\n", type);
+		}
 	}
 
 	closedir (dh);