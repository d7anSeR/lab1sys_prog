mkdir A
cd A
mkdir B
cd B
mkdir C D
cd C
head -c 256 /dev/urandom > 3.txt
ln 3.txt 1.txt
ln -s 3.txt 2.txt

cd ../
cd D
truncate -s 256 4.txt
truncate -s 256 5.txt
tr '\000' '\111' < 5.txt > 5.tmp && mv 5.tmp 5.txt
