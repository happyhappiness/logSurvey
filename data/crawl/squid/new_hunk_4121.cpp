int
match_user (char *dict_username, char *username)
{
    if ((strcmp (dict_username, username)) == 0) {
        return 1;
    } else {
        if ((strcmp (dict_username, "ALL")) == 0) {
            return 1;
        }
    }
    return 0;
}				/* match_user */

int
match_group (char *dict_group, char *username)
{
    struct group *g;		/* a struct to hold group entries */
    dict_group++;			/* the @ should be the first char
				   so we rip it off by incrementing
				   * the pointer by one */

    if ((g = getgrnam (dict_group)) == NULL) {
        fprintf (stderr, "helper: Group does not exist '%s'\n",
                 dict_group);
        return 0;
    } else {
        while (*(g->gr_mem) != NULL) {
            if (strcmp (*((g->gr_mem)++), username) == 0) {
                return 1;
            }
        }
    }
    return 0;

}				/* match_group */
