    int rm_obj = 0;

    if (table == (HashID) 0)
	return 0;

    /* Scan row of hash table each second and free storage if we're
     * over the high-water mark */
