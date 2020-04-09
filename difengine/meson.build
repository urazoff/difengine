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

eval_lib = static_library('evaluate',
                          'evaluate.c',
                           include_directories: global_inc)

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
