        err->xerrno = rd.xerrno;
        fwd->fail(err);
        flags.do_next_read = false;
        io.conn->close();

        return;
    }

