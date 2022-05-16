#include "benchmark/benchmark.h"
#include "split_string.h"

static void BM_FindFirstOf(benchmark::State &state) {
  for (auto _ : state) {
    auto arr = split(LoremIpsumStrv);
  }
}
static void BM_STDFindFirstOf(benchmark::State &state) {
  for (auto _ : state) {
    auto arr = splitStd(LoremIpsumStrv);
  }
}
static void BM_SplitPtr(benchmark::State &state) {
  for (auto _ : state) {
    auto arr = splitPtr(LoremIpsumStrv);
  }
}
static void BM_SplitSV(benchmark::State &state) {
  for (auto _ : state) {
    auto arr = splitSV(LoremIpsumStrv);
  }
}
static void BM_SplitSVStd(benchmark::State &state) {
  for (auto _ : state) {
    auto arr = splitSVStd(LoremIpsumStrv);
  }
}
static void BM_SplitSVPtr(benchmark::State &state) {
  for (auto _ : state) {
    auto arr = splitSVPtr(LoremIpsumStrv);
  }
}

BENCHMARK(BM_FindFirstOf);
BENCHMARK(BM_STDFindFirstOf);
BENCHMARK(BM_SplitPtr);
BENCHMARK(BM_SplitSV);
BENCHMARK(BM_SplitSVStd);
BENCHMARK(BM_SplitSVPtr);

BENCHMARK_MAIN();





