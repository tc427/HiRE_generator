#! /usr/bin/env bash

tdir="auto_tests"

gen="../../../build_v4/HiRE_parm"

basedir="base"
refdir="ref"

mkdir $tdir
cd $tdir || exit


function run_test {
    echo "$1"
    echo "========"
    mkdir "$1"
    cd "$1" || exit
    cp "../../${basedir}/${1}.pdb" ./
    ${gen} "${1}.pdb"
    grep -inr "type" parametres.csh
    diff -u "../../${refdir}/${1}" .
    cd .. || exit
}


for s1 in ../${basedir}/*pdb; do
    s2=$(basename ${s1})
    s3=${s2%%.*}
    run_test ${s3}
done
