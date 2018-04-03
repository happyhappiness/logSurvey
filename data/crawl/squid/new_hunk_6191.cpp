	i++;
#endif
#endif /* __CYGWIN32__ */
	fp = fopen("conftestval", "w");
	fprintf (fp, "%d\n", i);
	exit(0);
}
],
