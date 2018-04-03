 
     /* Initiate aio */
     if (aio_write(&qe->aq_e_aiocb) < 0) {
-	debug(1, 1) ("Aiee! aio_read() returned error (%d)!\n", errno);
+	fatalf("Aiee! aio_read() returned error (%d)!\n", errno);
 	assert(1 == 0);
     }
 }
