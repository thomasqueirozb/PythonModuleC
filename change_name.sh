#!/bin/bash

old_name="testc"
new_name=""

[ "$new_name" = "" ] && {
    >&2 echo "Change the new_name variable"
    exit 2
}

old_name_uppercase="${old_name^}"
new_name_uppercase="${new_name^}"
sed -i \
    -e "s/$old_name/$new_name/g" \
    -e "s/$old_name_uppercase/$new_name_uppercase/g" ./*.c ./*.h ./*.py .pylintrc Makefile
