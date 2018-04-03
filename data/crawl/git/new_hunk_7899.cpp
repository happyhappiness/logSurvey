						     ntohl(off64[1]);
				off64_nr++;
			}
			printf("%" PRIuMAX " %s (%08x)\n", (uintmax_t) offset,
			       sha1_to_hex(entries[i].sha1),
			       ntohl(entries[i].crc));
		}