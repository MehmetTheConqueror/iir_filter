#include "iir_filter.h"

iir_filter::iir_filter(std::vector<float> coeff_a, std::vector<float>coeff_b)
{
    this->coeff_a = coeff_a;
    this->coeff_b = coeff_b;

    for (int i=0; i < coeff_a.size(); i++)
        prev_outputs.push_back(0);

    for (int i=0; i < coeff_b.size(); i++)
        prev_inputs.push_back(0);
}

float iir_filter::get_filter_output(float input)
{
    float output = 0.0;

    if (coeff_b.size() > 0) {
        output = input*coeff_b.at(0);
        for (int i=0; i < coeff_b.size()-1; i++) {
            output += coeff_b.at(i+1) * prev_inputs.at(i);
        }
    }

    for (int i=0; i < coeff_a.size(); i++) {
        output += coeff_a.at(i) * prev_outputs.at(i);
    }

    if (prev_inputs.size() > 0) {
        prev_inputs.erase(prev_inputs.begin());
        prev_inputs.push_back(input);
    }

    if (prev_outputs.size() > 0) {
        prev_outputs.erase(prev_outputs.begin());
        prev_outputs.push_back(output);
    }

    return output;
}
