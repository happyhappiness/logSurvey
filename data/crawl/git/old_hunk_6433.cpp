		string_list_clear(info.list, 0);

		/* git push info */
		if (states.remote->push_refspec_nr) {
			printf("  Local branch%s pushed with 'git push'\n",
				states.remote->push_refspec_nr > 1 ?
					"es" : "");
			for (i = 0; i < states.remote->push_refspec_nr; i++) {
				struct refspec *spec = states.remote->push + i;
				printf("    %s%s%s%s\n",
				       spec->force ? "+" : "",
				       abbrev_branch(spec->src),
				       spec->dst ? ":" : "",
				       spec->dst ? abbrev_branch(spec->dst) : "");
			}
		}

		free_remote_ref_states(&states);
	}
