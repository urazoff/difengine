project('Difengine', 'C', version: '0.0.1')

cc = meson.get_compiler('c')

global_inc = include_directories('include')

wordsize = cc.sizeof('size_t') * 8
add_project_arguments('-DDF_WSIZE=@0@'.format(wordsize), language : 'c')

df_libs = []

subdir('front')
subdir('difengine')
subdir('tests')
