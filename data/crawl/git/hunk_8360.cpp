 	}
 	if (!src->index) {
 		src->index = create_delta_index(src->data, src_size);
-		if (!src->index)
-			die("out of memory");
+		if (!src->index) {
+			static int warned = 0;
+			if (!warned++)
+				warning("suboptimal pack - out of memory");
+			return 0;
+		}
 	}
 
 	delta_buf = create_delta(src->index, trg->data, trg_size, &delta_size, max_size);