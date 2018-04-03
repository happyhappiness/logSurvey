                          (int) head->min / 60,
                          (int) (100.0 * head->pct + 0.5),
                          (int) head->max / 60);
#if HTTP_VIOLATIONS

        if (head->flags.override_expire)
