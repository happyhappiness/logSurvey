 		for (i = 0; i < entries->nr; i++) {
 			struct stage_data *e = entries->items[i].util;
 			if (!e->processed)
-				die(_("Unprocessed path??? %s"),
+				die(_("BUG: unprocessed path??? %s"),
 				    entries->items[i].string);
 		}
 
