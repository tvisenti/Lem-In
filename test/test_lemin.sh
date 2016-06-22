#!/bin/sh

#
# This is a shell script in order to test your lem-in program.
#

test_errors1()
{
	for i in {1..22}
	do
		printf "\033[34;1m./lem-in < test/test_err%d.map\n\033[0m" $i
		./lem-in < test/test_err$i.map
		echo '-----'
	done
}

test_errors2()
{
	for i in {23..45}
	do
		printf "\033[34;1m./lem-in < test/test_err%d.map\n\033[0m" $i
		./lem-in < test/test_err$i.map
		echo '-----'
	done
}

test_valid1()
{
	for i in {1..15}
	do
		printf "\033[34;1m./lem-in < test/test_%d.map\n\033[0m" $i
		./lem-in < test/test_$i.map
		echo '-----'
	done
}

test_valid2()
{
	for i in {16..29}
	do
		printf "\033[34;1m./lem-in < test/test_%d.map\n\033[0m" $i
		./lem-in < test/test_$i.map
		echo '-----'
	done
}


test_big()
{
	for i in {1..5}
	do
		printf "\033[34;1m./lem-in < test/test_big%d.map\n\033[0m" $i
		./lem-in < test/test_$i.map
		echo '-----'
	done
}

# Checking if the program exist. If not: do make.
if [ ! -f ./lem-in ];
then
	make
fi

# Ask the user which test to launch.
while true; do
	echo "\033[34;1mChoose a test:\n
		[1]\tValids from 1 to 15\n
		[2]\tValids from 16 to 29\n
		[3]\tErrors from 1 to 22\n
		[4]\tErrors from 23 to 45\n
		[5-i]\tBig with i from 1 to 5\n
		[q]\tQuit\n
		\033[0m"
	read tests
	case $tests in
		"1" )		test_valid1 ;;
		"2" )		test_valid2 ;;
		"3" )		test_errors1 ;;
		"4" )		test_errors2 ;;
		"5-1" )		./lem-in < test/test_big1.map ;;
		"5-2" )		./lem-in < test/test_big2.map ;;
		"5-3" )		./lem-in < test/test_big3.map ;;
		"5-4" )		./lem-in < test/test_big4.map ;;
		"5-5" )		./lem-in < test/test_big5.map ;;
		"err" )		test_errors ;;
		"q" )		exit ;;
	esac
done
