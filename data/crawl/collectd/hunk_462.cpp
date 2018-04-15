 
 static int irq_config (char *key, char *value)
 {
-	unsigned int *temp;
-	unsigned int irq;
-        char *endptr;
-
 	if (strcasecmp (key, "Irq") == 0)
 	{
+		unsigned int *temp;
+		unsigned int irq;
+		char *endptr;
+
 		temp = (unsigned int *) realloc (irq_list, (irq_list_num + 1) * sizeof (unsigned int *));
 		if (temp == NULL)
 		{
-			syslog (LOG_EMERG, "Cannot allocate more memory.");
+			fprintf (stderr, "irq plugin: Cannot allocate more memory.\n");
+			syslog (LOG_ERR, "irq plugin: Cannot allocate more memory.");
 			return (1);
 		}
 		irq_list = temp;
 
-		irq = strtol(value, &endptr, base);
+		/* Clear errno, because we need it to see if an error occured. */
+		errno = 0;
 
-		if (endptr == value ||
-		    (errno == ERANGE && (irq == LONG_MAX || irq == LONG_MIN)) ||
-		    (errno != 0 && irq == 0))
+		irq = strtol(value, &endptr, 10);
+		if ((endptr == value) || (errno != 0))
 		{
-			syslog (LOG_EMERG, "Irq value is not a number.");
+			fprintf (stderr, "irq plugin: Irq value is not a "
+					"number: `%s'\n", value);
+			syslog (LOG_ERR, "irq plugin: Irq value is not a "
+					"number: `%s'", value);
 			return (1);
 		}
 		irq_list[irq_list_num] = irq;
