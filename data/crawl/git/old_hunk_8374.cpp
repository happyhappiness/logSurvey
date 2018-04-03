			printf("%-6s %lu %"PRIuMAX" %u %s\n",
			       type, size, (uintmax_t)offset,
			       delta_chain_length, sha1_to_hex(base_sha1));
			if (delta_chain_length < MAX_CHAIN)
				chain_histogram[delta_chain_length]++;
			else
				chain_histogram[0]++;
		}
	}

	for (i = 0; i < MAX_CHAIN; i++) {
		if (!chain_histogram[i])
			continue;
		printf("chain length %s %d: %d object%s\n",
		       i ? "=" : ">=",
		       i ? i : MAX_CHAIN,
		       chain_histogram[i],
		       1 < chain_histogram[i] ? "s" : "");
	}
}

int verify_pack(struct packed_git *p, int verbose)