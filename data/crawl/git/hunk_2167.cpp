 				      (unsigned char *)challenge_64, encoded_len);
 	if (decoded_len < 0)
 		die("invalid challenge %s", challenge_64);
-	HMAC_Init(&hmac, (unsigned char *)pass, strlen(pass), EVP_md5());
-	HMAC_Update(&hmac, (unsigned char *)challenge, decoded_len);
-	HMAC_Final(&hmac, hash, NULL);
-	HMAC_CTX_cleanup(&hmac);
+	if (!HMAC(EVP_md5(), pass, strlen(pass), (unsigned char *)challenge, decoded_len, hash, NULL))
+		die("HMAC error");
 
 	hex[32] = 0;
 	for (i = 0; i < 16; i++) {