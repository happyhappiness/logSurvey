            return;
        }

    /* XXX this may end up having to be serverComplete() .. */
        ftpState->abortTransaction("zero control reply read");
        return;
    }

