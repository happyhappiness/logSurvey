 				mi = (nr - 1) * (miv - lov) / (hiv - lov);
 				if (lo <= mi && mi < hi)
 					break;
-				die("oops");
+				die("BUG: assertion failed in binary search");
 			}
 		}
 		if (18 <= ofs)