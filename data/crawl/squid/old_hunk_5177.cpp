        i++;
#endif /* IF !DEF CYGWIN */
	fp = fopen("conftestval", "w");
	fprintf (fp, "%d\n", i);
	exit(0);
}
  ],
