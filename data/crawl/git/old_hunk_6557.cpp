		pll_free(perm_all);
	}
	if (perm_ok == NULL)
		die("Internal error: No complete sets found!\n");

	/* find the permutation with the smallest size */
	perm = perm_ok;
