mem_lib = static_library('memory',
                         'memory.c', 
                          include_directories: global_inc)
code_lib = static_library('code',
                          'code.c',
                           include_directories: global_inc,
                           link_with: mem_lib)
