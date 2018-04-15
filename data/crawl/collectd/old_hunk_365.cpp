}


/**********************************************************************
 * iptc cache utility functions (iptcc_*)
 **********************************************************************/

/* Is the given chain builtin (1) or user-defined (0) */
static unsigned int iptcc_is_builtin(struct chain_head *c)
{
	return (c->hooknum ? 1 : 0);
}
