#!/bin/sh

mkdir -p build

#
# Notes on the build process :
#
#	There is a circular dependency between page00.z80 and page1C.z80
#	at export level (each of these need to know the values exported
#	by the other). So NEVER EVER remove the .exp files or the build
#	process will be broken (to fix it you'll have to comment out all
#	references to page00 symbols in page1C (and files it includes),
#	compile once, uncomment and recompile everything).
#
#	Tasm syntax is used in the sources so you need an assembler that
#	is fully compatible with that syntax if you do not want to use
#	tasm.
#
#	A couple of undocumented instructions are used throughout the source
#	so a proper tasm80.tab is supplied to ensure a smooth build process
#

# behold the hackish handling of circular dependency
# [ really need a better assembler that can deal with this without such a crap...]

# build this before as we need to export some symbols
# for use by the OS basecode in page00
wine tools/tasm -80 -c -o20 -fC7 -y -e page1C.z80 build/page1C.hex &> /dev/null

if [ $? != 0 ]
then
	echo "errors in page 1C..." $?
	exit 1
fi

wine tools/tasm -80 -c -o20 -fC7 -y -e page00.z80 build/page00.hex

if [ $? != 0 ]
then
	echo "errors in page 00..." $?
	exit 1
fi

# update "SDK"
mv page00.exp xos.exp

# rebuild in case some symbols changed...
wine tools/tasm -80 -c -o20 -fC7 -y -e page1C.z80 build/page1C.hex

if [ $? != 0 ]
then
	echo "errors in page 1C..." $?
	exit 1
fi

wine tools/tasm -80 -c -o20 -fC7 -y -e page01.z80 build/page01.hex

if [ $? != 0 ]
then
	echo "errors in page 01..." $?
	exit 1
fi

tools/multihex 00 build/page00.hex 01 build/page01.hex 1C build/page1C.hex | tools/encdos build/xos.hex

tools/packxxu -v 0.1 -h 255 build/xos.hex -t 83p -q 0A -o build/xos.8xu &> /dev/null

rabbitsign -t 8xu -k tools/0A.key build/xos.8xu -o xos.8xu &> /dev/null

# create rom dump
tools/rom8x 84PBE -1 tools/D84PBE1.8xv -2 tools/D84PBE2.8xv -u xos.8xu

# build apps

for filename in apps/*.z80
do
	name=`basename $filename | sed s,\.z80$,,`
	
	wine tools/tasm -80 -b -c -fC7 -y apps/$name.z80 apps/$name.bin

	if [ $? != 0 ]
	then
		echo "errors..."
		exit 1
	fi

	tools/bin8x -i apps/$name.bin -o $name.8xp -n $name -83p &> /dev/null
done
