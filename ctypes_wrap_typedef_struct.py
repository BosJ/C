#!/usr/bin/python
# -*- coding: utf-8 -*-

'''
Wraps typedef struct as ctypes classes
https://docs.python.org/3/library/ctypes.html
https://github.com/eliben/pycparser
'''

import sys
from pycparser import c_ast, parse_file
from collections import OrderedDict

root_file   = "file_with_root_struct.h"
root_struct = "typedef_struct_var_name"

ast = parse_file(root_file, use_cpp=True)
unresolved = []


# Helper function to return 'typedef struct' AST node
def get_typedef(name):

    for node in ast.ext:
        if type(node) == c_ast.Typedef and node.name == name:
            return node.type.type


# Helper function to check if 'name' is a 'typedef struct' AST node
def is_struct(name):

    for node in ast.ext:
        if type(node) == c_ast.Typedef and node.name == name:
            return type(node.type.type) == c_ast.Struct


# From type t_name; create ctypes type
def type_to_ctype(t_name):

    c_type = ' '.join(t_name)

    if c_type in ('int', 'char', 'short', 'long', 'float', 'double', 'byte'):
        return 'c_' + c_type
    elif c_type == 'int32':
        return 'c_int'
    elif c_type in ('uint32', 'unsigned int'):
        return 'c_uint'
    elif c_type == 'word':
        return 'c_short'
    elif c_type == 'unsigned char':
        return 'c_ubyte'
    else:
        if is_struct(c_type):
            unresolved.append(c_type)
            return c_type
        else:
            return 'FIXME'


# Find struct_name in AST and get its members, optionally print as ctypes class
def c_struct_to_ctypes_class(struct_name, prnt):

    if prnt:
        print('class ' + struct_name + '(Structure):')
        print('\t_fields_ = [')

    for decl in get_typedef(struct_name):

        if type(decl.type) == c_ast.TypeDecl:
            name = decl.type.declname
            ctype = type_to_ctype(decl.type.type.names)
        elif type(decl.type) == c_ast.ArrayDecl:
            name = decl.type.type.declname
            ctype = type_to_ctype(decl.type.type.type.names) + \
                    ' * ' + decl.type.dim.value

        if prnt:
            print('\t\t("' + name + '", ' + ctype + '),')

    if prnt:
        print('\t]\n')


# Resolve dependencies, (nested) typedef members must be defined before defining
# the structure. The root_struct is traversed while collecting unresolved typedefs
# in order without printing.
c_struct_to_ctypes_class(root_struct, False)
for i in unresolved:
    c_struct_to_ctypes_class(i, False)

structs_list = list(OrderedDict.fromkeys(unresolved))
structs_list = list(reversed(structs_list))
structs_list.append(root_struct)


# Print all c-structs as ctypes classes in the correct order
for i in structs_list:
    c_struct_to_ctypes_class(i, True)
