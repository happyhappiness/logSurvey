          f->stem = strcache_add_len (buffer, o - buffer);
          if (this)
            {
              this->staticpattern = 1;
              this->stem = f->stem;
            }
        }

      name = f->name;
    }

  if (implicit)
    {
      if (deps)
        deps->need_2nd_expansion = second_expansion;
      create_pattern_rule (targets, target_percents, target_idx,
                           two_colon, deps, cmds, 1);
    }
}

