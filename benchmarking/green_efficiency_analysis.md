# Green Efficiency Analysis

## Measurement Methodology

The experiments were performed using the provided C programs without changing their algorithmic logic. All programs were compiled using the required compiler flags:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long
```

Execution time was measured using the `clock()` function from `<time.h>`. The elapsed time was calculated by subtracting the starting clock value from the ending clock value and dividing the result by `CLOCKS_PER_SEC`. To reduce the effect of small timing variations, the baseline and comparison programs were executed three consecutive times under the same environment.

For the instrumentation experiment, timing measurements were added around each program phase. Separate measurements were collected for dataset construction, dataset processing, checksum reduction, and the complete program execution.

## Observed Performance Differences

The baseline execution produced execution times of **0.219562**, **0.243031**, and **0.219101** seconds. The small differences between these measurements show that runtime can vary slightly even when the same program is executed repeatedly.

The comparison experiment showed a much larger performance difference. The naive implementation required an average of **2.662822 seconds**, while the single-pass implementation required only **0.000112 seconds**. Based on these measurements, the naive implementation was approximately **23,775 times slower** than the single-pass implementation.

The instrumentation experiment showed that the total execution time was **0.000696 seconds**. The measured phases were:

- Build dataset: **0.000257 seconds**
- Process dataset: **0.000303 seconds**
- Reduce checksum: **0.000131 seconds**

The processing phase consumed the largest portion of the execution time.

## Relation Between Runtime and Energy Consumption

Although this project did not measure electrical power directly, execution time provides a useful approximation of computational efficiency. A program that finishes faster generally keeps the CPU active for a shorter period of time. This suggests that more efficient algorithms may reduce energy consumption, especially when executed repeatedly or at large scale.

The large runtime difference between the naive algorithm and the single-pass algorithm demonstrates how algorithm design can significantly influence computational cost.

## Limitations of the Experiment

The experiment has several limitations. First, execution time can vary because of operating system scheduling, background processes, and CPU load. Second, only CPU execution time was measured; actual electrical power consumption was not measured. Finally, all measurements were collected on a single environment, so results may differ on different hardware or operating systems.

## Practical Engineering Takeaway

This project demonstrates that measuring performance should be part of normal software development. Rather than assuming one implementation is faster, developers should collect measurements and compare results under consistent conditions. Choosing efficient algorithms can greatly reduce execution time and may also reduce resource usage and energy consumption, particularly for applications that process large amounts of data or run continuously.
