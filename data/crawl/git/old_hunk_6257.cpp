	return 0;
}

int remote_find_tracking(struct remote *remote, struct refspec *refspec)
{
	int find_src = refspec->src == NULL;
