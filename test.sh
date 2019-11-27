#!/bin/bash
#
# Empty the PATH and check if '/bin/ls' still works (with path)

command="/bin/ls"

SLEEP=`which sleep`
SLEEPSECONDS=1

# empty PATH
OLDPATH="$PATH"
PATH=""

# run command
echo "$command" | ./hsh > ../salida 2> ../salidaerror &
echo "$command" | sh > ../sh 2> ../sherr

PATH="$OLDPATH"

"$SLEEP" "$SLEEP"SECONDS

diff ../salida ../sh
diff ../salidaerror ../sherr
