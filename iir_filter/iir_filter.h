#ifndef IIR_FILTER_H
#define IIR_FILTER_H

#include <vector>

class iir_filter
{
public:
    iir_filter(std::vector<float> coeff_a, std::vector<float>coeff_b);
    float get_filter_output(float input);

private:
    std::vector<float> coeff_a;     // for prev outputs
    std::vector<float> coeff_b;     // for prev inputs
    std::vector<float> prev_inputs;
    std::vector<float> prev_outputs;
};

#endif // IIR_FILTER_H
