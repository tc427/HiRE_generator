#! /usr/bin/env bash

basedir="base"


for s1 in "RNA" "DNA" "ions"; do
    run_test ${s1}
    for s2 in "RNA" "DNA" "ions"; do
        if [ $s1 == $s2 ]; then
            continue
            fi
        sd="${s1}_${s2}"
        cat ${basedir}/${s1}.pdb > ${basedir}/${sd}.pdb
        cat ${basedir}/${s2}.pdb >> ${basedir}/${sd}.pdb
    done
done
