# iir_filter

* Simple IIR Filter implementation in C++

Usage:

Create filter coefficients B and A as std::vector<float> (If vector B has zero length then filter is a FIR filter)

Create new iir_filter class instance by passing filter coefficients A and B as arguments

Call get_filter_output function of iir_filter class periodically by passing input signal value as argument and get filtred output value.

* Very simple filter simulation in Qt/C++
