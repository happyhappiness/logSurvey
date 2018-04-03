    X509_NAME_oneline(X509_get_subject_name(peer_cert), buffer,
                      sizeof(buffer));

    if (ok) {
        debugs(83, 5, "SSL Certificate signature OK: " << buffer);

