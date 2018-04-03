 			if (open_pack_index(p))
 				continue;
 			packed += p->num_objects;
+			size_pack += p->pack_size + p->index_size;
 			num_pack++;
 		}
 		printf("count: %lu\n", loose);
 		printf("size: %lu\n", loose_size / 2);
 		printf("in-pack: %lu\n", packed);
 		printf("packs: %lu\n", num_pack);
+		printf("size-pack: %lu\n", size_pack / 1024);
 		printf("prune-packable: %lu\n", packed_loose);
 		printf("garbage: %lu\n", garbage);
 	}
