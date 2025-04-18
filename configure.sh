#!/bin/bash

unset -v PREFIX
while getopts g:p: option; do
        case ${option} in
                p) PREFIX=$OPTARG ;;
                \?) echo "Unsupported option -$OPTARG." ;;
                :) echo "Option -$OPTARG requires an argument." ;;
        esac
done

shift "$((OPTIND - 1))"

if [[ -z "${PREFIX}" ]]; then
	echo "Error: PREFIX not defined"
	exit 1
else
	echo ${PREFIX} >> ${PWD}/.cache
        unset -v PREFIX
fi
