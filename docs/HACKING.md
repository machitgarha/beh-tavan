## Hacking BehTavan

Every project is hackable. Some easier. Here are some instructions on hacking the project, for the mentioned purposes.

### Adding New Power Function

1.  Add your function prototype to `include/functions/power.hpp`, inside `BehTavan` namespace. Your function must follow the same prototype as others.

1.  Implement your function in `src/functions/power.cpp`, though you are free to implement it in .hpp file.

1.  Navigate to `workflows/power-funcs-time-comparison-workflow.hpp`. Add your function information inside `PowerFuncsTimeComparisonWorkflow::getFunctionsInfo()` function, just like the others.

1.  Recompile and run. You should now see your new function in the results.

### Working with Other Operations?

TBD.
