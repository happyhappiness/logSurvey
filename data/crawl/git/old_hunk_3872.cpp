		printf("size-pack: %lu\n", (unsigned long) (size_pack / 1024));
		printf("prune-packable: %lu\n", packed_loose);
		printf("garbage: %lu\n", garbage);
	}
	else
		printf("%lu objects, %lu kilobytes\n",