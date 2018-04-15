{
    lvm_t lvm;
    vg_t vg;
    struct dm_list *vgnames;
    struct lvm_str_list *strl;

    lvm = lvm_init(NULL);
    if (!lvm) {
        fprintf(stderr, "lvm_init() failed\n");
    }

    vgnames = lvm_list_vg_names(lvm);
    if (!vgnames) {
        fprintf(stderr, "lvm_list_vg_names() failed\n");
    }

    dm_list_iterate_items(strl, vgnames) {
        vg = lvm_vg_open(lvm, strl->str, "r", 0);
        volume_submit(strl->str, lvm_vg_get_size(vg), lvm_vg_get_free_size(vg));
        lvm_vg_close(vg);
    }
