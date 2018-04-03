		printf("size-pack: %lu\n", (unsigned long) (size_pack / 1024));
		printf("prune-packable: %lu\n", packed_loose);
		printf("garbage: %lu\n", garbage);
		printf("size-garbage: %lu\n", (unsigned long) (size_garbage / 1024));
	}
	else
		printf("%lu objects, %lu kilobytes\n",