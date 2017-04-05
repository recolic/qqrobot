#!/bin/bash
declare -a farr
farr=($(ls ../QQRobotForBISTU | grep -E '(\.cpp$)|(\.hpp$)|(\.h$)|(\.c$)'))
for fpath in "${farr[@]}" 
do
	:
	if file --mime-encoding $fpath | grep 'iso-8859-1'; then
		echo "Converting $fpath ..."
	else
		echo "Refused: $fpath"
		continue
	fi
	if iconv -f "GB18030" -t "UTF-8" ../QQRobotForBISTU/$fpath -o ../QQRobotForBISTU/$fpath; then
		echo "Done."
	else
		echo "(At ../QQRobotForBISTU/$fpath)"
	fi
done
echo "Done."

