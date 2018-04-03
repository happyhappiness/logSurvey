 			case OBJ_BLOB:
 				handle_object(tag->object.sha1);
 				continue;
+			default:
+				warning("Tag points to object of unexpected type %s, skipping.",
+					typename(tag->object.type));
+				continue;
 			}
 			break;
 		default:
