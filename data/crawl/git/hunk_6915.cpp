 				printf("M %06o :%d %s\n", spec->mode,
 				       get_object_mark(object), spec->path);
 			}
+			break;
+
+		default:
+			die("Unexpected comparison status '%c' for %s, %s",
+				q->queue[i]->status,
+				ospec->path ? ospec->path : "none",
+				spec->path ? spec->path : "none");
 		}
 	}
 }
