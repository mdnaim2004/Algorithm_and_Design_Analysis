#!/usr/bin/env bash

# v1.5 Closebox73
# This script is linked to Eltanin.conf lines
# So don't  add a line there unless you change here too

COLOR=${1}

sleep 0.5s

if [ -x /usr/bin/figlet ] ; then
    figlet -t "Eltanin"
    echo "Color changer script"
    else
    echo "Eltanin color changer"
fi

sleep 1s
echo "Processing....."
sleep 2s

echo "Stoping Eltanin"
killall conky

sleep 0.7s
echo "Set up Accent"
sed -i "34s|color1 = .*|color1 = '${COLOR}',|" ~/.config/conky/Eltanin/Eltanin.conf &

sleep 1s
echo "Success.."

sleep 1s
read -n 1 -p "Do you want to start theme with clock? (y/n) : " num
 
case $num in
	[Nn]*)
	sleep 0.7s
	echo -e "\nRestarting Eltanin with new accent color..."
	sleep 1s
	conky -c $HOME/.config/conky/Eltanin/Eltanin.conf &> /dev/null &
	;;
	*)
	sleep 0.7s
	echo -e "\nRestarting Eltanin with new accent color..."
	sleep 1s
	conky -c $HOME/.config/conky/Eltanin/Eltanin.conf &> /dev/null &
	conky -c $HOME/.config/conky/Eltanin/Eltanin2.conf &> /dev/null &
	;;
esac
	
sleep 5s
echo "Done"

exit
