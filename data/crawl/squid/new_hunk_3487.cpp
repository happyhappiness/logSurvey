                      ms.bytes_total >> 10);

    storeAppendPrintf(sentry, "\tTotal free:            %6d KB %d%%\n",
                      ms.bytes_free >> 10, Math::intPercent(ms.bytes_free, ms.bytes_total));

#elif HAVE_MALLINFO && HAVE_STRUCT_MALLINFO

