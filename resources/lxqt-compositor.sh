#!/data/data/com.termux/files/usr/bin/bash

# Program settings

EDITOR="featherpad"
ROOT_DIR="/data/data/com.termux/files/usr/var/lib/lxqt-compositor"

# Basic compositor settings

# xcompmgr (alias Xorg) settings -----------------------------------
# enter arguments to launch xcompmgr

XORG_ARGS="-C -n"

# xcompmgr (alias Xorg) settings -----------------------------------

# functions

# please no edit ---------------------------------------------------

if [ $@ == "--use-picom" ]; then
    picom -b --config $ROOT_DIR/picom.conf &
    sed -i 's|Exec=/data/data/com.termux/files/usr/var/lib/lxqt-compositor/lxqt-compositor.sh --use-xorg|Exec=/data/data/com.termux/files/usr/var/lib/lxqt-compositor/lxqt-compositor.sh --use-picom|g' $PREFIX/etc/xdg/autostart/lxqt-composer.desktop 2> /dev/null

elif [ $@ == "--use-xorg" ]; then
    xcompmgr $XORG_ARGS
    sed -i 's|Exec=/data/data/com.termux/files/usr/var/lib/lxqt-compositor/lxqt-compositor.sh --use-picom|Exec=/data/data/com.termux/files/usr/var/lib/lxqt-compositor/lxqt-compositor.sh --use-xorg|g' $PREFIX/etc/xdg/autostart/lxqt-composer.desktop 2> /dev/null

elif [ $@ == "--picom-conf" ]; then
    $EDITOR $ROOT_DIR/picom.conf

elif [ $@ == "--xorg-conf" ]; then
    $EDITOR $ROOT_DIR/lxqt-compositor.sh

else
    echo "error, invalid option $@"
fi

# please no edit ---------------------------------------------------
