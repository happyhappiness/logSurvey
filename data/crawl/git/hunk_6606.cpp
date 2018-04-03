 		die("%s: error reading the index", me);
 		break;
 	case WRITE_TREE_UNMERGED_INDEX:
-		die("%s: error building trees; the index is unmerged?", me);
+		die("%s: error building trees", me);
 		break;
 	case WRITE_TREE_PREFIX_ERROR:
 		die("%s: prefix %s not found", me, prefix);
