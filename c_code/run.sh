set -e
gcc /home/christopherdumas/fly_wm/c_code/flywm.c -o /home/christopherdumas/fly_wm/c_code/flywm -lX11
XEPHYR=$(whereis -b Xephyr | cut -f2 -d' ')
xinit /home/christopherdumas/fly_wm/c_code/flywm-session -- \
  "$XEPHYR" \
  :100 \
  -ac \
  -screen 1080x720 \
  -host-cursor
