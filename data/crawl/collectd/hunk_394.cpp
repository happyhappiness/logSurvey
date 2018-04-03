 #else
 	if (ksp == NULL)
 	{
-		fprintf (stderr, "ERROR: %s:%i: ksp == NULL\n", __FILE__, __LINE__);
+		ERROR ("ERROR: %s:%i: ksp == NULL\n", __FILE__, __LINE__);
 		return (-1LL);
 	}
 	else if (ksp->ks_type != KSTAT_TYPE_NAMED)
 	{
-		fprintf (stderr, "ERROR: %s:%i: ksp->ks_type != KSTAT_TYPE_NAMED\n", __FILE__, __LINE__);
+		ERROR ("ERROR: %s:%i: ksp->ks_type != KSTAT_TYPE_NAMED\n", __FILE__, __LINE__);
 		return (-1LL);
 	}
 #endif
