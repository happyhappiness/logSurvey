 {
 	if (strcasecmp (key, "Irq") == 0)
 	{
-		unsigned int *temp;
-		unsigned int irq;
-		char *endptr;
+		char **temp;
 
-		temp = (unsigned int *) realloc (irq_list, (irq_list_num + 1) * sizeof (unsigned int *));
+		temp = realloc (irq_list, (irq_list_num + 1) * sizeof (*irq_list));
 		if (temp == NULL)
 		{
 			fprintf (stderr, "irq plugin: Cannot allocate more memory.\n");
