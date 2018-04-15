 	}
 	DEBUG ("interval_g = %i;", interval_g);
 
+	str = global_option_get ("Timeout");
+	if (str == NULL)
+		str = "10";
+	timeout_g = atoi (str);
+	if (timeout_g <= 0)
+	{
+		fprintf (stderr, "Cannot set the timeout to a correct value.\n"
+				"Please check your settings.\n");
+		return (-1);
+	}
+	DEBUG ("timeout_g = %i;", timeout_g);
+
 	if (init_hostname () != 0)
 		return (-1);
 	DEBUG ("hostname_g = %s;", hostname_g);
