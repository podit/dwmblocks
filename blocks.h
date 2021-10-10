//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/

  // filesystem usage info
  {" ~: ", "lsblk -o label,fsavail,size | awk '/^hom/ { print $2\"/\"$3 }'", 30, 0},
  {" /: ", "lsblk -o label,fsavail,size | awk '/^rut/ { print $2\"/\"$3 }'", 30, 0},
  
  // memory usage info
	{" swp: ", "free -h --si | awk '/^Swap/ { print $3\"/\"$2 }'",	30,		0},
	{" mem: ", "free -h --si | awk '/^Mem/ { print $3\"/\"$2 }'",	30,		0},

  // cpu load info
  // TODO: uptime output will change length, awk method will not handle this at
  //  present. awk can do logic so look into replacing the `sed`s in bat info
  //{" cpu: ", "uptime | awk '{ print

  // battery info
  // TODO: trim third value (Y) from remaining time (XX:XX:YY)
  {" bat: ", "acpi -b | awk '/^Battery 0:/ {print $4\" \"$3\" \"$5 }' | sed s/,//g | sed s/Discharging/-/g | sed s/Charging/+/g | sed s/Unknown/u/g | sed s/Full/f/g | sed s/f\" \"/f/g", 30, 0},

	{" ", "date '+%b %d (%a) %H:%M'",					5,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " |";
static unsigned int delimLen = 5;
