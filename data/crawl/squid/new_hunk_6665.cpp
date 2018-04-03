print_stats()
{
	getrusage(RUSAGE_SELF, &myusage);
	printf("m/c/f/r=%d/%d/%d/%d\n",mstat.mallocs,mstat.callocs,
					mstat.frees, mstat.reallocs);
	printf("types                 : %d\n",size2id_len);
	printf("user time used        : %d.%d\n", (int)myusage.ru_utime.tv_sec,
						(int)myusage.ru_utime.tv_usec);
