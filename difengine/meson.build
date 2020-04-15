mem_lib = static_library('memory',
                         'memory.c',
                          include_directories: global_inc)

code_lib = static_library('code',
                          'code.c',
                           include_directories: global_inc,
                           link_with: mem_lib)

frame_lib = static_library('frame',
                           'frame.c',
                            include_directories: global_inc,
                            link_with: mem_lib)

int_lib = static_library('int',
                         'intobject.c',
                          include_directories: global_inc,
                          link_with: mem_lib)

ops_lib = static_library('ops',
                         'objectops.c',
                          include_directories: global_inc,
                          link_with: int_lib)

eval_lib = static_library('evaluate',
                          'evaluate.c',
                           include_directories: global_inc,
                           link_with: ops_lib)

list_lib = static_library('list',
                          'listobject.c',
                           include_directories: global_inc,
                           link_with: mem_lib)

bytes_lib = static_library('bytes',
                           'bytesobject.c',
                            include_directories: global_inc,
                            link_with: mem_lib)

dis_lib = static_library('dis',
                         'dis.c',
                          include_directories: global_inc)
