 			if (!(data->flags & ADD_CACHE_PRETEND))
 				remove_file_from_index(&the_index, path);
 			if (data->flags & (ADD_CACHE_PRETEND|ADD_CACHE_VERBOSE))
-				printf("remove '%s'\n", path);
+				printf(_("remove '%s'\n"), path);
 			break;
 		}
 	}
