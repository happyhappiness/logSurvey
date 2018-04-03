      {
      default:
      case o_invalid:
        abort ();
        break;
      case o_default:
        o = variable_buffer_output (o, "default", 7);
        break;
      case o_env:
        o = variable_buffer_output (o, "environment", 11);
        break;
      case o_file:
        o = variable_buffer_output (o, "file", 4);
        break;
      case o_env_override:
        o = variable_buffer_output (o, "environment override", 20);
        break;
      case o_command:
        o = variable_buffer_output (o, "command line", 12);
        break;
      case o_override:
        o = variable_buffer_output (o, "override", 8);
        break;
      case o_automatic:
        o = variable_buffer_output (o, "automatic", 9);
        break;
      }

  return o;
