 		{
 			fprintf (stderr, "irq plugin: Irq value is not a "
 					"number: `%s'\n", value);
-			syslog (LOG_ERR, "irq plugin: Irq value is not a "
+			ERROR ("irq plugin: Irq value is not a "
 					"number: `%s'", value);
 			return (1);
 		}
