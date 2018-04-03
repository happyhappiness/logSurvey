 			*sizep = size;
 		break;
 	default:
-		die("pack %s contains unknown object type %d",
-		    p->pack_name, type);
+		error("unknown object type %i at offset %"PRIuMAX" in %s",
+		      type, (uintmax_t)obj_offset, p->pack_name);
+		type = OBJ_BAD;
 	}
 	unuse_pack(&w_curs);
 	return type;
