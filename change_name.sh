#!/bin/bash

old_name="testc"
new_name="socembarcados"

[ "$new_name" = "" ] && {
    >&2 echo "Change the new_name variable"
    exit 2
}

old_name_uppercase="${old_name^}"
new_name_uppercase="${new_name^}"
sed -i \
    -e "s/$old_name/$new_name/g" \
    -e "s/$old_name_uppercase/$new_name_uppercase/g" ./*.c ./*.h ./*.py .pylintrc Makefile

for file in ./*; do
    (grep "$old_name" <<< "$file") && mv "$file" "$(echo "$file" | sed "s|$old_name|$new_name|g")"
done
