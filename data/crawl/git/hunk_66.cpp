 			else
 				printf("%s\n", i1);
 
-		} else if (!strcmp("perfhashmap", cmd) && l1 && l2) {
+		} else if (!strcmp("perfhashmap", cmd) && p1 && p2) {
 
 			perf_hashmap(atoi(p1), atoi(p2));
 