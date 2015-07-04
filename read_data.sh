while [ 1 ]
do
  READ=`dd if=/dev/ttyUSB0 count=1`
  echo $READ > data/temperature.data
done