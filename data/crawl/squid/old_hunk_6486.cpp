        close(i); close(i-1);
	i++;
#endif
	fprintf (fopen("conftestval", "w"), "%d\n", i);
	exit(0);
}
