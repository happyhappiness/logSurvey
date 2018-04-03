            memcpy(read_buf, buf, len);

        callback(cbdata, read_buf, len);
    }

    if (closing)
        fatal("Sync ufs doesn't support overlapped close and read calls\n");
}

