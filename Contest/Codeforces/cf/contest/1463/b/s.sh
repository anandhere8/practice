for((i = 0; i < 100000 ; i++)) do
  echo $i
  ./gen $i > in
  # ./brute < in > out2
  ./b < in > out1
  # diff -w out1 out2 || break
done
