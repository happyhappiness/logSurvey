    if (h != NULL)
        h->stop("ACL");
#endif
    if (callback_data)
        cbdataReferenceDone(callback_data);
}

void
