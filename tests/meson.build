tests = [['code', ['code.c']],
         ['object', ['object.c']],
         ['list', ['list.c']]]

foreach t:tests
    exe = executable(t[0], t[1], include_directories: global_inc,
                     link_with: [code_lib, dis_lib, 
                                 list_lib, bytes_lib])
endforeach
