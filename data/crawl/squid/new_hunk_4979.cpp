            const int saved_id = err->page_id;
            err->page_id = ERR_SQUID_SIGNATURE;
            MemBuf *sign_mb = errorBuildContent(err);
            mb.Printf("%s", sign_mb->content());
            sign_mb->clean();
            delete sign_mb;
            err->page_id = saved_id;
            do_quote = 0;
