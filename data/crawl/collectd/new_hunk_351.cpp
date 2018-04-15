	return (status_code);
} /* int do_check_con_sum */

static int do_check_con_percentage (int values_num, double *values, char **values_names)
{
        int i;
	double percentage;

	if (values_num != 2)
		return (RET_WARNING);
	if (isnan (values[0]) || isnan (values[1]))
		return (RET_WARNING);
	if ((values[0] + values[1]) == 0)
		return (RET_WARNING);

        percentage = 100 * values[1] / ( values[0] + values[1] );

	printf ("%lf percentage |", percentage);
	for (i = 0; i < values_num; i++)
		printf (" %s=%lf;;;;", values_names[i], values[i]);

	if (match_range (&range_critical_g, percentage) != 0)
	{
		printf ("CRITICAL: percentage = %lf\n", percentage);
		return (RET_CRITICAL);
	}
	else if (match_range (&range_warning_g, percentage) != 0)
	{
		printf ("WARNING: percentage = %lf\n", percentage);
		return (RET_WARNING);
        }

        printf ("OKAY: percentage = %lf\n", percentage);
        return (RET_OKAY);
} /* int do_check_con_percentage */

static int do_check (void)
{
	lcc_connection_t *connection;
