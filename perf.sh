make re
make clean
./generator/./generator 10 10
time ./depth/./solver ./mazes/first_test
time ./breadth/./solver ./mazes/first_test
