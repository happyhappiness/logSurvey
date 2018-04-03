
int remote_find_tracking(struct remote *remote, struct refspec *refspec)
{
	int i;
	for (i = 0; i < remote->fetch_refspec_nr; i++) {
		struct refspec *fetch = &remote->fetch[i];
		if (!fetch->dst)
			continue;
		if (fetch->pattern) {
			if (!prefixcmp(refspec->src, fetch->src)) {
				refspec->dst =
					xmalloc(strlen(fetch->dst) +
						strlen(refspec->src) -
						strlen(fetch->src) + 1);
				strcpy(refspec->dst, fetch->dst);
				strcpy(refspec->dst + strlen(fetch->dst),
				       refspec->src + strlen(fetch->src));
				refspec->force = fetch->force;
				return 0;
			}
		} else {
			if (!strcmp(refspec->src, fetch->src)) {
				refspec->dst = xstrdup(fetch->dst);
				refspec->force = fetch->force;
				return 0;
			}
		}
	}
	refspec->dst = NULL;
	return -1;
}

