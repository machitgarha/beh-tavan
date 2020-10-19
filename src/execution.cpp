#include "execution.hpp"

using namespace BehTavan;

template<typename TimeUnit>
ExecutionTimeVector BehTavan::execute(
    const PowerFunctionInfoVector &powerFuncsInfo,
    Base base,
    Exponent exponent
) {
   using namespace TimeMeasuring;

   const size_t powerFuncsSize = powerFuncsInfo.size();
   ExecutionTimeVector times;
   Int64 outputs[powerFuncsSize];

   for (size_t i = 0; i < powerFuncsSize; i++) {
       times.push_back(
           measureFuncExecTime<TimeUnit>(
               outputs[i], powerFuncsInfo[i].ptr, base, exponent
           )
       );

       // Ensure all results are equal
       if (i != 0 && outputs[i] != outputs[i - 1]) {
           throw std::runtime_error("Power functions do not produce the same output");
       }
   }

   return times;
}

// Specializations
using namespace TimeMeasuring::TimeUnit;
template ExecutionTimeVector BehTavan::execute<Seconds>(
    const PowerFunctionInfoVector &, Base, Exponent
);
template ExecutionTimeVector BehTavan::execute<Milliseconds>(
    const PowerFunctionInfoVector &, Base, Exponent
);
template ExecutionTimeVector BehTavan::execute<Microseconds>(
    const PowerFunctionInfoVector &, Base, Exponent
);
template ExecutionTimeVector BehTavan::execute<Nanoseconds>(
    const PowerFunctionInfoVector &, Base, Exponent
);
