#!/bin/bash

LIB_DIR="/usr/lib"
FUNCTIONS=("sin" "cos" "exp")

for lib in $(find "$LIB_DIR" -name "*.so"); do
	for func in "${FUNCTIONS[@]}"; do
		if nm -D "$lib" 2>/dev/null | grep -w "$func" > /dev/null; then
			echo "Lib $lib have func $func"
		fi
	done 
done
