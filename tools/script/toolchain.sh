#!/bin/bash

#!/bin/bash

CONFIG=.config
DESINC=core/rm_config.h

rm -rf $DESINC

if [ ! -f "$CONFIG" ]
then
    echo "\033[31;1m.config lost!"
    echo "Please use make menuconfig to rebuilt one.\033[0m"
    exit 1;
fi

while read LINE
do
    if  [ "${LINE:0:1}" =  "#" ]
    then
        continue
    fi

    if  [[ $LINE =~ "CONFIG_TOOLCHAIN_TYPE=" ]]
    then
        DEF=${LINE//CONFIG_TOOLCHAIN_TYPE=/}
        if  [ "$DEF" !=  "" ]
        then
            echo ${DEF//\"}
        fi
    fi

done  < $CONFIG

