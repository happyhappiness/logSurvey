 			|| ((type_instance != NULL)
 				&& (strlen (type_instance) >= sizeof (vl.type_instance))))
 	{
-		fprintf (fh, "-1 Identifier too long.");
+		fprintf (fh, "-1 Identifier too long.\n");
 		return (-1);
 	}
 
