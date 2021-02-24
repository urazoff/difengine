tests = [['code', ['code.c']],
         ['object', ['object.c']],
         ['list', ['list.c']],
         ['frame', ['frame.c']],
         ['evaluate', ['evaluate.c']],
         ['lexer', ['lexer.c']],
         ['parser', ['parser.c']],
         ['hash', ['hash.c']],
         ['integer', ['int.c']]]

foreach t:tests
    exe = executable(t[0], t[1], include_directories: global_inc,
                     link_with: df_libs)
endforeach
