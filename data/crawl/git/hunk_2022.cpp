 				PROT_READ, MAP_PRIVATE,
 				p->pack_fd, win->offset);
 			if (win->base == MAP_FAILED)
-				die("packfile %s cannot be mapped: %s",
-					p->pack_name,
-					strerror(errno));
+				die_errno("packfile %s cannot be mapped",
+					  p->pack_name);
 			if (!win->offset && win->len == p->pack_size
 				&& !p->do_not_close)
 				close_pack_fd(p);