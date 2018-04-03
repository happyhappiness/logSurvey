			num_pack++;
		}
		printf("count: %lu\n", loose);
		printf("size: %lu\n", (unsigned long) (loose_size / 1024));
		printf("in-pack: %lu\n", packed);
		printf("packs: %lu\n", num_pack);
		printf("size-pack: %lu\n", (unsigned long) (size_pack / 1024));
		printf("prune-packable: %lu\n", packed_loose);
		printf("garbage: %lu\n", garbage);
	}
	else
		printf("%lu objects, %lu kilobytes\n",
		       loose, (unsigned long) (loose_size / 1024));
	return 0;
}