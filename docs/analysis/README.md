# Analysis

Here, we are going to grab some of the useful results from the program's output.

## Power Functions

Currently, in this project, we have two functions to raise a number to another one:

-   `power()`: It uses the normal algorithm, multiplying the base until reaching the exponent.

-   `powerOptimized()`: As its name represents, it has an optimized algorithm. First, it handles special cases. If the base is 0 and 1, then the result is 0 and 1, respectively. If the exponent is 0, then the result is always 1.

    Skipping these, we reach the main part. If the exponent is even, then we can write the result as, square of the base raised to half of exponent, e.g. 2^100 is converted to 4^50. Otherwise, the exponent is odd, so we can decrease exponent by one, make it even, and multiply the result to the current base, e.g. 4^25 is written as 4^24 * 4. We continue this action until the exponent reaches 1.

### Sample Output

Good to see one. With `INTERACTIVE=0` environment variable set, we get something like this:

```
...

base = 3
Time unit is in nanoseconds.

+----------+----------+----------------+
|          |  power   | powerOptimized |
+----------+----------+----------------+
|    1     |   1724   |      355       |
+----------+----------+----------------+
|    5     |   375    |      424       |
+----------+----------+----------------+
|    10    |   455    |      360       |
+----------+----------+----------------+
|   100    |   1337   |      509       |
+----------+----------+----------------+
|   1000   |   8786   |      510       |
+----------+----------+----------------+
|  10000   |  90880   |      730       |
+----------+----------+----------------+
|  100000  |  911247  |      795       |
+----------+----------+----------------+
| 1000000  | 7428375  |      585       |
+----------+----------+----------------+
| 10000000 | 30305330 |      366       |
+----------+----------+----------------+
```

### Performance Notes

Generally, the performance overhead of `power()` is much much bigger than `powerOptimized()`. This is the power of optimization!

-   The performance of `power()` highly depends on the size of the inputs, either the base or the exponent. However, for `powerOptimized()`, it performs almost independently from the inputs, and the speed remains the same.

-   For small inputs, the execution time is totally equal. Say, approximately, if the base equals 3, then for exponent less than 1000, the difference is negligible. From somewhere, the difference increases drastically, and `powerOptimized()` performs pretty much better.

-   Increasing the base in both has little impact on both. But again, its impact is minimal in `powerOptimized()`. By increasing, I mean changing it exponentially.

-   Sometimes, the result of the last time results in `powerOptimized()` column is a bit less than expected (as you could see in the previous section). This might not be a performance notice comparing the two functions. Instead, it may be the result of caching (e.g. by OS or CPU), or something else.
