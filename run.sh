set -e
gcc flywm.c lib/hashmap.c -o flywm -lX11
gcc apps/taskmaster.c -o apps/taskmaster -lX11
XEPHYR=$(whereis -b Xephyr | cut -f2 -d' ')
xinit ./flywm-session -- \
  "$XEPHYR" \
  :100 \
  -ac \
  -screen 1080x720 \
  -host-cursor
