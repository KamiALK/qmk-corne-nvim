#!/usr/bin/env bash

qmk compile -kb crkbd/rev1 -km kamilo
qmk flash -kb crkbd/rev1 -km kamilo
