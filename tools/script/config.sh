#!/bin/bash

CONFIG=.config
DESINC=core/rm_module.h

rm -rf $DESINC

if [ -f "$CONFIG" ]
then
    echo "find .config file!"
else
    echo "\033[31;1m.config lost!"
    echo "Please use make menuconfig to rebuilt one.\033[0m"
    exit 1;
fi

echo "#ifndef _RM_CONFIG_H_" >> $DESINC
echo "#define _RM_CONFIG_H_" >> $DESINC
echo "" >> $DESINC
while read LINE
do
    if  [ "${LINE:0:1}" =  "#" ]
    then
        continue
    fi

    DEF=${LINE//=y/}
    if  [ "$DEF" !=  "" ]
    then
        echo "#define BTL_"${DEF/CONFIG_/}" 1" >> $DESINC
    fi
done  < $CONFIG

echo "" >> $DESINC
echo "#endif" >> $DESINC

