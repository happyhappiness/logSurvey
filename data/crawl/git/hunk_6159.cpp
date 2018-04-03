 			case OBJ_BLOB:
 				handle_object(tag->object.sha1);
 				continue;
+			default: /* OBJ_TAG (nested tags) is already handled */
+				warning("Tag points to object of unexpected type %s, skipping.",
+					typename(tag->object.type));
+				continue;
 			}
 			break;
 		default:
-			die ("Unexpected object of type %s",
-			     typename(e->item->type));
+			warning("%s: Unexpected object of type %s, skipping.",
+				e->name,
+				typename(e->item->type));
+			continue;
 		}
 		if (commit->util)
 			/* more than one name for the same object */
