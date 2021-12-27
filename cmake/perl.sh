#!/bin/bash

#echo "$1 is $2"
perl -0pe 's/(\#ifdef Q_SPY.*?\#else)(.*?)(\#endif)/\2/gs' $1 > $2