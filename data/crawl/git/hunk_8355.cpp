 		 */
 		if (0x03030303 < acc ||
 		    0xffffffff - de < (acc *= 85))
-			error("invalid base85 sequence %.5s", buffer-5);
+			return error("invalid base85 sequence %.5s", buffer-5);
 		acc += de;
 		say1(" %08x", acc);
 