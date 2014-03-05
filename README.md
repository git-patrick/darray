darray
======

Container compatible with std::array which dynamically allocates storage thus allowing O(1) moves instead of std::array's O(n) moves.

Example output for darray performance test application...

```
     0    std::array<std::array<float,100>, 100000> w/ 0 moves
   104    std::array<darray<float,100>, 100000> w/ 0 moves
     0    std::array<std::array<float,100000>, 100> w/ 0 moves
    64    std::array<darray<float,100000>, 100> w/ 0 moves
   272    std::array<std::array<float,100>, 100000> w/ 50 moves
   162    std::array<darray<float,100>, 100000> w/ 50 moves
   253    std::array<std::array<float,100000>, 100> w/ 50 moves
    63    std::array<darray<float,100000>, 100> w/ 50 moves
  2469    std::array<std::array<float,100>, 100000> w/ 500 moves
   737    std::array<darray<float,100>, 100000> w/ 500 moves
  2450    std::array<std::array<float,100000>, 100> w/ 500 moves
    61    std::array<darray<float,100000>, 100> w/ 500 moves
```
