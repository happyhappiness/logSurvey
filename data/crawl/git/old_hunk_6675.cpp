		show_list("  Tracked remote branch%s", &states.tracked, "");

		if (states.remote->push_refspec_nr) {
			printf("  Local branch%s pushed with 'git push'\n   ",
				states.remote->push_refspec_nr > 1 ?
					"es" : "");
			for (i = 0; i < states.remote->push_refspec_nr; i++) {
				struct refspec *spec = states.remote->push + i;
				printf(" %s%s%s%s", spec->force ? "+" : "",
				       abbrev_branch(spec->src),
				       spec->dst ? ":" : "",
				       spec->dst ? abbrev_branch(spec->dst) : "");
			}
			printf("\n");
		}

		/* NEEDSWORK: free remote */
